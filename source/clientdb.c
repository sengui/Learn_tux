/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------      
 *      "Basic Synchronous Database Client"
 *
 */

#include <stdio.h>
#include <time.h>
#ifdef WIN32
#include <sys/types.h>
#endif
#include <sys/timeb.h>
#include "atmi.h"		/* TUXEDO  Header File */
#include "Uunix.h"		/* TUXEDO  Header File */
#include "userlog.h"		/* TUXEDO  Header File */

static int verbose = 0, iter = 1, mywait = 0;

void
#if defined(__STDC__) || defined(__cplusplus)
usage(char *name)
#else
usage(name)
     char *name;
#endif
{
  (void)fprintf(stderr, "Usage:\n %s -s <service_name> -i <iterations> "
		"-w <wait_time> [-v]\n", name);
  (void)fprintf(stderr, "     where: <service_name> is required\n");
  (void)fprintf(stderr, "            <iterations> is optional (defaults "
		"to 1, 50 maximum)\n");
  (void)fprintf(stderr, "            <wait_time> is optional (defaults "
		"to 0)\n");
  (void)fprintf(stderr, "            -v turns on verbose mode\n");
  return;
}

long
#if defined(__STDC__) || defined(__cplusplus)
ourtime()
#else
ourtime()
#endif
{
  struct timeb tb;
  (void)ftime(&tb);
  return ((long)((tb.time & (time_t)0x000fffff) * 1000) + tb.millitm);
}

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
     int argc;
     char *argv[];
#endif
{
  char *service = NULL, *buffer;
  long buflen = 100;
  int verbose = 0, c, cd, i, ret;
  long start_time, end_time;

  while((c = getopt(argc, argv, "i:s:w:v")) != EOF) {
    switch((char)c) {
    case 'i':	/* iterations */
      iter = atoi(optarg) ;
      break ;

    case 's':	/* service name */
      service = optarg;
      break;

    case 'w':	/* wait time */
      mywait = atoi(optarg) ;
      break;

    case 'v':	/* verbose */
      verbose = 1;
      break;

    default:
      usage(argv[0]);
      exit(1);
    }
  }

  if ((NULL == service) || (50 < iter)) {
    usage(argv[0]);
    exit(1);
  }

  /*
   * Attach to System/T as a Client Process
   */
  if (tpinit((TPINIT *)NULL) == -1) {
    (void)fprintf(stderr, "Tpinit failed: %s\n", tpstrerror(tperrno));
    exit(1);
  }

  /*
   * Allocate STRING buffers for the request
   */
  if((buffer = (char *)tpalloc("STRING", NULL, buflen)) == NULL) {
    (void)fprintf(stderr, "Error allocating send buffer: %s\n",
		  tpstrerror(tperrno));
    (void)tpterm();
    exit(1);
  }

  /*
   * Request the service for defined number of times async.
   */
  for (i = 1; i <= iter; i++) {
    sprintf(buffer, "%d clientdb %d\n", i, (int)time(NULL));
    start_time = ourtime();
	if (verbose) {
		fprintf(stdout, "Request #%d sent to %s\n", i, service);
	}
    if (0 > (tpcall(service, (char *)buffer, 0,
		    (char **)&buffer, &buflen, TPSIGRSTRT))) {
      (void)fprintf(stderr, "Can't send request to service %s: %s\n",
		    service, tpstrerror(tperrno));
      tpfree(buffer);
      (void)tpterm();
      exit(1);
    }

    if (verbose) {
      end_time = ourtime();
      fprintf(stdout, "Request #%d completed -- response time = %3.5f "
	      "seconds \n", i, ((double)(end_time - start_time) / 1000.0));
      fprintf(stdout, "\n");
    }

    if (mywait)
      sleep(mywait);
  }

  /*
   * Free Buffers & Detach from TUXEDO
   */
  tpfree(buffer);
  (void)tpterm();
  return(0);
}

