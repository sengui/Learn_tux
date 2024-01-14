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
 * clientenqueue.c
 * "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "atmi.h"
#include "fml32.h"
#include "userlog.h"
#include "recordfml.h"

#ifdef WIN32
#define PATH_DELIMITER         '\\'
#else
#define PATH_DELIMITER         '/'
#endif /* WIN32 */

#define NS      6       /* Number of string fields */
#define MXSTR   80      /* Maximum string length   */

#define LEN ((NS*MXSTR))

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
  char f_name[MXSTR], l_name[MXSTR], address[MXSTR], city[MXSTR], state[MXSTR], input[MXSTR];
  char *error;
  long len;
  FILE *file;
  FLDLEN32 len2;
  TPQCTL qctl;
  char *programName;

  argc = argc;
  argv = argv;

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
    (void)userlog("Clientenqueue failed to join application  -- %s\n",
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

  file = fopen("address.data", "r");
  if (file == NULL) {
    (void)fprintf(stderr, "File open error: %s\n", strerror(errno));
    (void)userlog("Clientenqueue file open error: %s\n", strerror(errno));
    (void)tpfree((char *)f);
    (void)tpterm();
    (void)exit(1);
  }

  while ((error = (fgets(input, 80, file))) != NULL) {

    (void)strcpy(f_name,strtok(input, "	"));
    (void)strcpy(l_name,strtok(NULL, "	"));
    (void)strcpy(address,strtok(NULL, "	"));
    (void)strcpy(city,strtok(NULL, "	"));
    (void)strcpy(state,strtok(NULL, "	"));

    if (Fchg32(f, FIRSTNAME, 0, f_name, 0) == -1) {
      (void)fprintf(stderr, "Failure to change FIRSTNAME field -- %s\n",
	  	  Fstrerror32(Ferror32));
      (void)userlog("Clientenqueue failed to change FIRSTNAME field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    if (Fchg32(f, LASTNAME, 0, l_name, 0) == -1) {
      (void)fprintf(stderr, "Failure to change LASTNAME field -- %s\n",
	  	  Fstrerror32(Ferror32));
      (void)userlog("Clientenqueue failed to change LASTNAME field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    if (Fchg32(f, ADDRESS, 0, address, 0) == -1) {
      (void)fprintf(stderr, "Failure to change ADDRESS field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientenqueue failed to change ADDRESS field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    if (Fchg32(f, CITY, 0, city, 0) == -1) {
      (void)fprintf(stderr, "Failure to change CITY field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientenqueue failed to change CITY field -- %s\n",
 		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    if (Fchg32(f, STATE, 0, state, 0) == -1) {
      (void)fprintf(stderr, "Failure to change STATE field -- %s\n",
		  Fstrerror32(Ferror32));
      (void)userlog("Clientenqueue failed to change STATE field -- %s\n",
 		  Fstrerror32(Ferror32));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }

    if (tpbegin(30,0) == -1) {
      (void)fprintf(stderr, "Failed to begin transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)userlog("Clientenqueue failed to begin transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpterm();
      exit(1);
    }

    qctl.flags = TPQREPLYQ;
    (void)strcpy(qctl.replyqueue,"ReplyQ");

    if (tpenqueue("QSPACE", "ZIPCODEFINDER", (TPQCTL *)&qctl,
		(char *)f, 0, TPSIGRSTRT) == -1) {
      (void)fprintf(stderr, "Failure to enqueue ZIPCODEFINDER service -- %s \n",
		  tpstrerror(tperrno));
      (void)userlog("Clientenqueue failed to enqueue ZIPCODEFINDER service -- %s \n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpabort(0);
      (void)tpterm();
      (void)exit(1);
    }

    if (tpcommit(0) == -1 ) {
      (void)fprintf(stderr, "Failed to commit transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)userlog("Clientenqueue failed to commit transaction -- %s\n",
		  tpstrerror(tperrno));
      (void)tpfree((char *)f);
      (void)tpterm();
      (void)exit(1);
    }
  }  /*end while loop*/
    (void)printf("\n *** Successful Enqueuing of 10 customer records ***\n");
  (void)tpfree((char *)f);
  (void)tpterm();
  return(0);
}
