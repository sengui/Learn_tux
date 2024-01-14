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

#include <stdio.h>
#include <ctype.h>
#include <atmi.h>	/* TUXEDO Header File */
#include <userlog.h>	/* TUXEDO Header File */

static int counter;

/* tpsvrinit is executed when a server is booted, before it begins
   processing requests.  It is not necessary to have this function.
   Also available is tpsvrdone (not used in this example), which is
   called at server shutdown time.
*/

#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
int argc;
char **argv;
#endif
{
	/* Some compilers warn if argc and argv aren't used. */
	argc = argc;
	argv = argv;

	counter=0;

	/* userlog writes to the central TUXEDO message log */
	userlog("Welcome to the A server");
	return(0);
}

/* This function performs the actual service requested by the client.
   Its argument is a structure containing among other things a pointer
   to the data buffer, and the length of the data buffer.
*/

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
SVCA(TPSVCINFO *rqst)
#else
SVCA(rqst)
TPSVCINFO *rqst;
#endif
{

	char *rcvbuf;
	long rcvlen;
    
	if((rcvbuf = (char *) tpalloc("STRING", NULL, 10)) == NULL) {
		(void) userlog("Error allocating rcvbuf");
		tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
	}

	if (counter == 3)
	{
	    	(void) userlog("To call SVCC. Data: %s", rqst->data);
		tpcall("SVCC", rqst->data, rqst->len, (char **)&rcvbuf, &rcvlen, (long)0);
		counter=0;
	}
	else
	{
	    	(void) userlog("To call SVCB. Data: %s", rqst->data);
		tpcall("SVCB", rqst->data, rqst->len, (char **)&rcvbuf, &rcvlen, (long)0);
		counter++;
	}

	/* Return the received buffer to the requestor. */
	tpreturn(TPSUCCESS, 0, rcvbuf, 0L, 0);
}
