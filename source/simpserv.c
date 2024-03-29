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

	/* userlog writes to the central TUXEDO message log */
	userlog("Welcome to the simple server");
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
TOUPPER(TPSVCINFO *rqst)
#else
TOUPPER(rqst)
TPSVCINFO *rqst;
#endif
{

	int i;

	for(i = 0; i < rqst->len-1; i++)
		rqst->data[i] = toupper(rqst->data[i]);

	/* Return the transformed buffer to the requestor. */
	tpreturn(TPSUCCESS, 0, rqst->data, 0L, 0);
}
