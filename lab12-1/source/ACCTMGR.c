/*	
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 */

#ifndef NOWHAT
static	char	sccsid[] = "@(#) apps/bankapp/ACCTMGR.c	$Revision: 1.5 $";
#endif

/*
 * This translation unit contains code that makes up a TUXEDO server that
 * on booting subscribes to the events "BANK_TLR_*" and "BANK_CTR_*". It
 * requests that if "BANK_TLR_*" events are received, it be notified via
 * a call to the service "WATCHDOG" and if "BANK_CTR_*" events are received,
 * it be queued into an application queue, "Q_OPENACCT_LOG". A TMQFORWARD
 * server that is configured, will forward the messages in the queue to the
 * service by the same name when the queue's hi-water mark is reached.
 * Both these services log the event to stdout.
 */

#include <stdio.h>		/* UNIX */
#include <string.h>		/* UNIX */
#ifdef _TMFML32
#include <fml32.h>		/* TUXEDO */
#include <fml1632.h>		/* TUXEDO */
#include <Usysfl32.h>		/* TUXEDO */
#else
#include <fml.h>		/* TUXEDO */
#include <Usysflds.h>		/* TUXEDO */
#endif
#include <atmi.h>		/* TUXEDO */
#include <Uunix.h>		/* TUXEDO */
#include <userlog.h>		/* TUXEDO */
#include "bank.h"		/* BANKING #defines */
#include "bankflds.h"		/* bankdb fields */
#include "eventflds.h"		/* event fields */

/* Event Subscription handles */
static long	sub_ev_largeamt = 0L ;
static long 	sub_ev_openacct = 0L ;


/* ARGSUSED */
int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char **argv)
#else
tpsvrinit(argc,argv)
int argc;
char **argv;
#endif

{

int	c ;
char 	amt_expr[80] ;
TPEVCTL evctl ;

    /* Preset default for option 'w' - watchdog threshold */

    (void)strcpy (amt_expr, "AMOUNT > 10000.00") ;

    /* Process any command line options if specified */

    while (c = getopt (argc,argv,"w:L:"),
	   c != EOF)
	switch ((char) c) {
	    case 'w':
		    if (optarg == NULL) {
			(void)userlog("WARN: Option 'w' requires an argument, Using default expr -- '%s'",
			amt_expr) ;
		    }
		    else
			(void)sprintf (amt_expr, "AMOUNT > %s", optarg) ;
		    break ;

	    default :
		    (void)userlog("WARN: Invalid Option -- '-%c' ... Ignoring",
				  (char) c) ;
	}

    /*
     * Subscribe to the events generated by the services DEPOSIT,
     * and WITHDRAWAL when a "large" amount is transacted.
     */

    evctl.flags = TPEVSERVICE ;
    (void)strcpy (evctl.name1, "WATCHDOG") ;

    /* Subscribe */

    sub_ev_largeamt = tpsubscribe ("BANK_TLR_.*",
				   amt_expr,
				   &evctl,
				   TPSIGRSTRT) ;
    if (sub_ev_largeamt == -1L) {
	(void)userlog ("ERROR: tpsubscribe for event BANK_TLR_.* failed: %s",
			tpstrerror(tperrno)) ;
	return -1 ;
    }

    /*
     * Subscribe to the event generated by the OPEN_ACCT service when a 
     * new account is opened so that a welcome package may be sent.
     */
    evctl.flags = TPEVQUEUE ;
    (void)strcpy (evctl.name1, "QSP_BANKAPP") ;
    (void)strcpy (evctl.name2, "Q_OPENACCT_LOG") ;

    evctl.qctl.flags = TPQFAILUREQ | TPQPRIORITY ;
    (void)strcpy (evctl.qctl.failurequeue, "Q_ERROR") ;
    evctl.qctl.priority = 10L ;

    /* Subscribe */

    sub_ev_openacct = tpsubscribe ("BANK_CTR_.*",
				   NULL,
				   &evctl,
				   TPSIGRSTRT);
    if (sub_ev_openacct == -1L) {
	(void)userlog ("ERROR: tpsubscribe to event BANK_CTR_.* failed: %s",
			tpstrerror(tperrno)) ;
	return -1 ;
    }

    return 0 ;
}

void
tpsvrdone()
{

    /* Unsubscribe to the subscribed events */

    if (tpunsubscribe (sub_ev_largeamt, TPSIGRSTRT) == -1)
	(void)userlog ("ERROR: tpunsubscribe to event BANK_TLR_.* failed: %s",
			 tpstrerror(tperrno)) ;

    if (tpunsubscribe (sub_ev_openacct, TPSIGRSTRT) == -1)
	(void)userlog ("ERROR: tpunsubscribe to event BANK_CTR_.* failed: %s",
			 tpstrerror(tperrno)) ;

    return ;
}


/*
 * Service called when a BANK_TLR_.* event is posted.
 */

void
#if defined(__STDC__) || defined(__cplusplus)
WATCHDOG(TPSVCINFO *transb)

#else

WATCHDOG(transb)
TPSVCINFO *transb;
#endif

{

FBFR *transf;		/* fielded buffer of decoded message  */

	/* Set pointr to TPSVCINFO data buffer  */
	transf = (FBFR *)transb->data;

	/* Print the log entry  to stdout */
	(void)fprintf (stdout, "%20s|%28s|%8ld|%10.2f\n",
				Fvals (transf, EVENT_NAME, 0), 
				Fvals (transf, EVENT_TIME, 0), 
				Fvall (transf, ACCOUNT_ID, 0),
		    *( (float *)CFfind (transf, AMOUNT, 0, NULL, FLD_FLOAT)) );

	/* No data should be returned by the event subscriber's svc routine */
	tpreturn(TPSUCCESS, 0,NULL, 0L, 0);
}




/*
 * Service that the TMQFORWARD server calls to log new accounts opened
 */

void
#if defined(__STDC__) || defined(__cplusplus)
Q_OPENACCT_LOG(TPSVCINFO *transb)

#else

Q_OPENACCT_LOG(transb)
TPSVCINFO *transb;
#endif

{

FBFR *transf;		/* fielded buffer of decoded message  */

	/* Set pointr to TPSVCINFO data buffer  */
	transf = (FBFR *)transb->data;

	/* Print the log entry */
	(void)fprintf (stdout, "%20s|%28s|%8ld|%10.2f\n",
				Fvals (transf, EVENT_NAME, 0), 
				Fvals (transf, EVENT_TIME, 0), 
				Fvall (transf, ACCOUNT_ID, 0),
		    *( (float *)CFfind (transf, AMOUNT, 0, NULL, FLD_FLOAT)) );

	/* No data is returned to the application Q */
	tpreturn(TPSUCCESS, 0,NULL, 0L, 0);
}
