/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------     
 * "/Q Configuration Lab"
 * clientdequeue.c
 * "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include "atmi.h"
#include "fml32.h"
#include "userlog.h"
#include "recordfml.h"
#include "Uunix.h"		/* TUXEDO  Header File */

#ifdef WIN32
#define PATH_DELIMITER         '\\'
#else
#define PATH_DELIMITER         '/'
#endif /* WIN32 */

#define NS      6       /* Number of string fields */
#define MXSTR   80      /* Maximum string length   */

#define LEN ((NS*MXSTR))

static int iter = -1;

void
#if defined(__STDC__) || defined(__cplusplus)
usage(char *name)
#else
usage(name)
     char *name;
#endif
{
  (void)fprintf(stderr, "Usage:\n %s -i <iterations> \n", name);
  (void)fprintf(stderr, "     where: <iterations> is the number of records to be retrieved\n");
  return;
}

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main (argc, argv)
   int argc;
   char *argv[];
#endif
{
  FBFR32 *f;
  char f_name[MXSTR], l_name[MXSTR], address[MXSTR], city[MXSTR], state[MXSTR], zipcode[MXSTR];
  long len;
  FLDLEN32 len2;
  TPQCTL qctl;
  char *programName;
  int i, c;

   while((c = getopt(argc, argv, "i:")) != EOF) {
     switch((char)c) {
    case 'i':	/* iterations */
      iter = atoi(optarg) ;
      break ;

    default:
      usage(argv[0]);
      exit(1);
    }
  }

  if ((iter < 1)) {
    usage(argv[0]);
    exit(1);
  }

  /*
   * Set the external variable proc_name (defined in userlog.h)
   * to be the name of the executable program so that it appears
   * in the Tuxedo ULOG entries for the client program.
   */

  programName = strrchr(argv[0], PATH_DELIMITER);
  if (programName == NULL) {
    proc_name = argv[0];
  }
  else {
    proc_name = &programName[1];
  }

   if (tpinit((TPINIT *)NULL) == -1) {
    (void)fprintf(stderr, "Failed to join application  -- %s\n",
		  tpstrerror(tperrno));
    (void)userlog("Clientpost failed to join application  -- %s\n",
		  tpstrerror(tperrno));
    (void)exit(1);
  }

  if ((f = (FBFR32 *)tpalloc("FML32", NULL, Fneeded32(NS, LEN))) == NULL) {
    (void)fprintf(stderr, "Failure to allocate FML32 buffer -- %s\n",
		  tpstrerror(tperrno));
    (void)userlog("Clientenqueue failed to allocate FML32 buffer -- %s\n",
		  tpstrerror(tperrno));
    (void)tpterm();
    (void)exit(1);
  }

  for (i = 1; i <= iter; i++) {

    if (tpbegin(30,0) == -1) {
      (void)fprintf(stderr, "Failed to begin transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)userlog("Clientenqueue failed to begin transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpterm();
      exit(1);
    }

    qctl.flags = TPNOFLAGS;

    if (tpdequeue("QSPACE", "ReplyQ", (TPQCTL *)&qctl,
		(char **)&f, &len, TPSIGRSTRT) == -1) {
      if ((tperrno == TPEDIAGNOSTIC) && (qctl.diagnostic == QMENOMSG)) {
         (void)fprintf(stderr, "Queue is empty -- terminating process.\n");
         (void)userlog("Clientdequeue reports queue is empty -- terminating process.\n");
         (void)tpfree((char *)f);
         (void)tpabort(0);
         (void)exit(1);
      }
      (void)fprintf(stderr, "Failure to dequeue from the ReplyQ -- %s \n",
		  tpstrerror(tperrno));
      (void)userlog("Clientdequeue failed to dequeue from the ReplyQ -- %s \n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpabort(0);
      (void)tpterm();
      (void)exit(1);
    }

    if (tpcommit(0) == -1 ) {
      (void)fprintf(stderr, "Failed to commit transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(f_name);
    if (Fget32(f, FIRSTNAME, 0, f_name, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get FIRSTNAME field -- %s\n",
	 	  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get FIRSTNAME field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(l_name);
    if (Fget32(f, LASTNAME, 0, l_name, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get LASTNAME field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get LASTNAME field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(address);
    if (Fget32(f, ADDRESS, 0, address, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get ADDRESS field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get ADDRESS field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(city);
    if (Fget32(f, CITY, 0, city, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get CITY field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get CITY field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(state);
    if (Fget32(f, STATE, 0, state, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get STATE field -- %s\n",
 		  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get STATE field -- %s\n",
 		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    len2 = sizeof(zipcode);
    if (Fget32(f, ZIPCODE, 0, zipcode, &len2) == -1) {
      (void)fprintf(stderr, "Failure to get ZIPCODE field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientdequeue failed to get ZIPCODE field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    (void)printf("Name: %s %s \nAddress: %s\nCity/State/Zip:  %s, %s %s\n\n",
        f_name, l_name, address, city, state, zipcode);

    sleep(1);

  }  /*end for loop */

  tpfree((char *)f);
  (void)tpterm();
  return(0);
}
