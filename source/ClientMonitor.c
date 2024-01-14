/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------     
 *  "ACMD Lab"
 *  "clientMonitor.c"
 *  "Version 1.0"
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fml32.h>		/* TUXEDO */
#include "atmi.h"
#include "userlog.h"
#include "evt_mib.h"

TPEVCTL	evctl;		/* event control struct */
long eventHandle = 0L ;

int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
	int	argc;
	char	**argv;
#endif
{
	// The following two lines prevent warning messages from lint and some compilers.
	argc = argc;
	argv = argv;
	// Write an initialization message to the user log.
	(void)userlog("Initializing %s.", argv[0]);

	// Subscribe to the Tuxedo System Event Broker
	evctl.flags = TPEVSERVICE ;
	(void)strcpy (evctl.name1, "WATCHDOG") ;
	eventHandle = tpsubscribe ("\\.SysClientDied","",&evctl,TPSIGRSTRT) ;
	if (eventHandle == -1L) {
     (void)userlog ("ERROR: tpsubscribe for the .SysClientDied event failed in ClientMonitor Server: %s",tpstrerror(tperrno)) ;
     return -1 ;
	}
	return(0);
} // end of tpsvrinit routine

/*
* Service called when the System event is posted.
*/
void
#if defined(__STDC__) || defined(__cplusplus)
WATCHDOG(TPSVCINFO *transb)
#else
WATCHDOG(transb)
TPSVCINFO *transb;
#endif
{
FBFR32 *transf; /* fielded buffer of decoded message  */
/* Set pointr to TPSVCINFO data buffer  */
transf = (FBFR32 *)transb->data;

     (void)userlog("*********") ;
     (void)userlog("Entering the WATCHDOG service...") ;
	(void)userlog("WATCHDOG NOTICE: A client has abnormally disconnected from Tuxedo...");
	(void)userlog("User: %s | ClientID: %s | LMID: %s | PID: %d",
		Fvals32 (transf, TA_USRNAME, 0),
		Fvals32 (transf, TA_CLIENTID, 0),
		Fvals32 (transf, TA_LMID, 0),
		Fvall32 (transf, TA_PID, 0));
     (void)userlog("...Exiting the WATCHDOG service") ;
     (void)userlog("*********") ;

	/* No data should be returned by the event subscriber's svc routine */
	tpreturn(TPSUCCESS, 0,NULL, 0L, 0);
}
