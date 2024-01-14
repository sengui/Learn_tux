/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------     
 * "Basic Database Big Update Server"
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

int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char **argv)
#else
tpsvrinit(argc,argv)
int argc;
char **argv;
#endif
{	
	int testNum = 100;
	sleep(1);
	srand((unsigned int)time(NULL));
	userlog("Initialized the Random Number Generator in BigUpdate Server\n");
	testNum = rand() % 10000;
	testNum = rand() % 10000;
	testNum = rand() % 10000;
	testNum = rand() % 10000;
	testNum = rand() % 10000;
	testNum = rand() % 10000;
	userlog("The initial random number is %d\n", testNum);


    return 0 ;
}


void
#if defined(__STDC__) || defined(__cplusplus)
BigUpdate(TPSVCINFO *rqst)
#else
BigUpdate(rqst)
     TPSVCINFO *rqst;
#endif
{
  char	*input;
	int randNum=0;

  /*
   * Assign a local pointer to the data portion of the buffer
   */
  input = rqst->data;

  userlog("BigUpdate routine received request %s timestamp = %d\n",
	  input, time(NULL));

// The following code creates a 20% chance that the server will "hang"
//	srand((unsigned int)time(NULL));
	randNum = rand() % 10000;
	userlog("The random number is %d\n", randNum);
	if(randNum < 8000)
		sleep(5);
	else
		sleep(3000);
// If the random number is 0 to 8, processing will take 5 sec
//   otherwise the service is "stuck" for 50 minutes

  /*
   * Return the transformed buffer to the requestor.
   */
  input = tprealloc(input, rqst->len + 20);
  tpreturn(TPSUCCESS, 0, input, 0L, 0);
}
