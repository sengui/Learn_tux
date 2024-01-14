/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------     
 * "TMQ Configuration Lab"
 * clientdequeue.c
 * "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include "atmi.h"
#include "fml32.h"
#include "recordfml.h"
#include "Uunix.h"		/* TUXEDO  Header File */
#include "tmqentry.h"
#include "tmqreturn.h"

void print_diagnostic(int nDiagnostic);

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
usage(char *name)
{
    fprintf(stderr, "Usage:\n %s -i <iterations> \n", name);
    fprintf(stderr, "     where: <iterations> is the number of records to be retrieved\n");
    return;
}

int
main(int argc, char *argv[])
{
    FBFR32 *f;
    char f_name[MXSTR], l_name[MXSTR], address[MXSTR], city[MXSTR], state[MXSTR], zipcode[MXSTR];
    long len;
    FLDLEN32 len2;
    TPQCTL qctl;
    char *programName;
    int i, c;

    TPQCTL ctl;
    Q_ATTACH_CTL qattachctl;
    long flags;
    int32 arg_list = TMQ_NOFLUSH_Q;
    int32 arg_count = 1;
    int32 purge_count;

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

    if (tpinit((TPINIT *)NULL) == -1) {
        fprintf(stderr, "Failed to join application  -- %s\n", tpstrerror(tperrno));
        exit(1);
    }

    if ((f = (FBFR32 *)tpalloc("FML32", NULL, Fneeded32(NS, LEN))) == NULL) {
        fprintf(stderr, "Failure to allocate FML32 buffer -- %s\n", tpstrerror(tperrno));
        tpterm();
        exit(1);
    }

    

    for (i = 1; i <= iter; i++) {
        qctl.flags = TPNOFLAGS;

        memset(&qattachctl, 0x0, sizeof(qattachctl));
        qattachctl.attachmode = TMQ_ATTACH_BY_NAME;
        qattachctl.qtype = TMQ_ATTACH_PQ;
        qattachctl.namespace_list = NULL;
        qattachctl.namespace_list_len = 0;
        qattachctl.timeout = 30;

        memset(&qctl, 0x0, sizeof(qctl));
        qctl.flags |= OTMQ;
        flags = TPNOTRAN;

        /* Attach to TMQ QSPACE */
        if (tpqattach("QSPACE", "ZIPCODEFINDER", &qctl, &qattachctl, flags) == -1)
        {
            fprintf(stderr, "failed to attach q[QSPACE.ZIPCODEFINDER]: %s\n", tpstrerror(tperrno));
            if (tperrno == TPEDIAGNOSTIC)
            {
                print_diagnostic(qctl.diagnostic);
            }
            tpfree((char *) f);
            tpabort(0);
            tpterm();
            exit(1);
        }

        /* Dequeue from ZIPCODEFINDER TMQ queue */
        ctl.timeout = 30;
        len=Fsizeof32(f);
        if (tpdeqplus("QSPACE", "ZIPCODEFINDER", &qctl, (char **)&f, &len, 0) == -1)
        {
            fprintf(stderr, "Failure to dequeue ZIPCODEFINDER service -- %s \n", tpstrerror(tperrno));
            if (tperrno == TPEDIAGNOSTIC)
            {
                print_diagnostic(qctl.diagnostic);
            }
            tpfree((char *) f);
            tpabort(0);
            tpterm();
            exit(1);
        }

        /* Call ZIPCODEFINDER Service */
        len=Fsizeof32(f);
        if (tpcall("ZIPCODEFINDER", (char *)f, 0, (char **)&f, &len, 0) == -1) {
	        fprintf(stderr, "ERROR: tpcall(ZIPCODEFINDER) failed (%s)\n", tpstrerror(tperrno));
            tpfree((char *) f);
            tpterm();
            exit(1);
		}

        /* Detach from TMQ QSPACE */
        if (tpqdetach("QSPACE", "ZIPCODEFINDER", &arg_list, arg_count, &purge_count, 0) == -1)
        {
            fprintf(stderr, "Failure to detach: %s\n", tpstrerror(tperrno));
            if (tperrno == TPEDIAGNOSTIC)
            {
                print_diagnostic(qctl.diagnostic);
            }
            tpfree((char *) f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(f_name);
        if (Fget32(f, FIRSTNAME, 0, f_name, &len2) == -1) {
            fprintf(stderr, "Failure to get FIRSTNAME field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(l_name);
        if (Fget32(f, LASTNAME, 0, l_name, &len2) == -1) {
            fprintf(stderr, "Failure to get LASTNAME field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(address);
        if (Fget32(f, ADDRESS, 0, address, &len2) == -1) {
            fprintf(stderr, "Failure to get ADDRESS field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(city);
        if (Fget32(f, CITY, 0, city, &len2) == -1) {
            fprintf(stderr, "Failure to get CITY field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(state);
        if (Fget32(f, STATE, 0, state, &len2) == -1) {
            fprintf(stderr, "Failure to get STATE field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        len2 = sizeof(zipcode);
        if (Fget32(f, ZIPCODE, 0, zipcode, &len2) == -1) {
            fprintf(stderr, "Failure to get ZIPCODE field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        printf("Name: %s %s \nAddress: %s\nCity/State/Zip:  %s, %s %s\n\n", f_name, l_name, address, city, state, zipcode);
        sleep(1);
    }  /*end for loop */

    tpfree((char *)f);
    tpterm();
    return(0);
}

void print_diagnostic(int nDiagnostic)
{
    fprintf(stderr, "Diagnostic code=[%d]\t", nDiagnostic);
    switch (nDiagnostic)
    {
    case -178/*QMBADSELIDX*/:
        fprintf(stderr, "Invalid or undefined selective receive index.\n");
        break;
    case QMENOMSG:
        fprintf(stderr, "There is no message in Queue.\n");
        break;
    default:
        fprintf(stderr, "\n");
        break;
    }
}

