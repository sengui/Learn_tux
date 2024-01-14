/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 *      "Basic Database Update Server"
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
Update(TPSVCINFO *rqst)
#else
Update(rqst)
     TPSVCINFO *rqst;
#endif
{
  char	*input;

  /*
   * Assign a local pointer to the data portion of the buffer
   */
  input = rqst->data;

  userlog("SvrUpdate received request %s timestamp = %d\n",
	  input, time(NULL));

  /*
   * Assume a delay of 5 seconds for a database update
   */
  sleep(5);

  /*
   * Return the transformed buffer to the requestor.
   */
  input = tprealloc(input, rqst->len + 20);
  tpreturn(TPSUCCESS, 0, input, 0L, 0);
}
