/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------     
 *      "Basic Database Delete Server"
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <atmi.h>	/* TUXEDO Header File */
#include <userlog.h>	/* TUXEDO Header File */

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
Delete(TPSVCINFO *rqst)
#else
Delete(rqst)
     TPSVCINFO *rqst;
#endif
{
  char	*input;

  input = rqst->data;

  userlog("Delete server received request %s timestamp = %d\n",
	  input, time(NULL));

  /*
   * Assume a 4 second sleep for the delay for a database deletion
   */
  sleep(4);

  /*
   * Return the transformed buffer to the requestor.
   */
  input = tprealloc(input, rqst->len + 20);
  tpreturn(TPSUCCESS, 0, input, 0L, 0);
}
