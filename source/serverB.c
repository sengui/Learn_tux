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
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int doforward;

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
	int c = 0;
	int len = 0;

	/* userlog writes to the central TUXEDO message log */
	userlog("Welcome to the B server");
    
	doforward = 0;
    (void) userlog("forward ska vara 0: %i", doforward);

	while((c = getopt(argc, argv, "f:")) != EOF) {
		switch((char)c) {
		case 'f':
			len = strlen(optarg);
			if (len > 1)
			{
				(void) userlog("CLOPT value is too long. Should be Y or N. Actual value: %s", optarg);
				return(-1);
			}
			(void) userlog("c=%c  optarg=%s", c, optarg);

			if (!strcmp(optarg,"N"))
			{
				doforward = 0;
				(void) userlog("CLOPT value is N.");
			}
			else if (!strcmp(optarg,"Y"))
			{
				doforward = 1;
				(void) userlog("CLOPT value is Y.");
			}
			else
			{
				(void) userlog("CLOPT value is unknown. Should be Y or N. Actual value: %s", optarg);
				return(-1);
			}

			break;
		default:
			/* Unknown CLOPT */
			(void) userlog("Unknown CLOPT in ubb file: %c", c);
			return(-1);
			break;
		}
	}
    (void) userlog("forward kan vara 1: %i", doforward);
    
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
SVCB(TPSVCINFO *rqst)
#else
SVCB(rqst)
TPSVCINFO *rqst;
#endif
{
	char *rcvbuf;
	long rcvlen;
    (void) userlog("forward: %i", doforward);

    if (doforward == 1)
    {
        tpforward("SVCC", rqst->data, rqst->len, 0);
    }
    else
    {

	if((rcvbuf = (char *) tpalloc("STRING", NULL, rqst->len)) == NULL) {
		(void) userlog("Error allocating rcvbuf");
		tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
	}
    
(void) userlog("To call SVCC. Data: %s", rqst->data);
    tpcall("SVCC", rqst->data, rqst->len, (char **)&rcvbuf, &rcvlen, (long)0);

	/* Return the received buffer to the requestor. */
	tpreturn(TPSUCCESS, 0, rcvbuf, rcvlen, 0);
     }
}
