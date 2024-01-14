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
 * clientenqueue.c
 * "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "atmi.h"
#include "fml32.h"
#include "recordfml.h"
#include "tmqentry.h"

#define PATH_DELIMITER         '/'

#define NS      6       /* Number of string fields */
#define MXSTR   80      /* Maximum string length   */

#define LEN ((NS*MXSTR))

#ifndef MSG_CLAS_EXAMPLES
#define MSG_CLAS_EXAMPLES            2000
#define MSG_TYPE_CLIENT_REQ             1
#define MSG_TYPE_SERVER_RESP            2
#endif

void print_diagnostic(int nDiagnostic);

int
main(int argc, char *argv[])
{
    /* /Q vars */
    FBFR32 *f;
    char f_name[MXSTR], l_name[MXSTR], address[MXSTR], city[MXSTR], state[MXSTR], input[MXSTR];
    char *error;
    int ret;
    FILE *file;
    FLDLEN32 len2;
    Q_ATTACH_CTL qattachctl;
    TPQCTL qctl;
    char *programName;
    int32 arg_list = TMQ_NOFLUSH_Q;
    int32 arg_count = 1;
    int32 purge_count;
    long del_mode = OTMQ_DEL_WF;

    long flags;
    long len; 

    if (tpinit((TPINIT *)NULL) == -1) {
        fprintf(stderr, "Failed to join application  -- %s\n", tpstrerror(tperrno));
        exit(1);
    }

    if ((f = (FBFR32 *)tpalloc("FML32", NULL, Fneeded32(NS, LEN))) == NULL) {
        fprintf(stderr, "Failure to allocate FML32 buffer -- %s\n", tpstrerror(tperrno));
        tpterm();
        exit(1);
    }

    file = fopen("address.data", "r");
    if (file == NULL) {
        fprintf(stderr, "File open error: %s\n", strerror(errno));
        tpfree((char *)f);
        tpterm();
        exit(1);
    }

    while ((error = (fgets(input, 80, file))) != NULL) {
        strcpy(f_name,strtok(input, "	"));
        strcpy(l_name,strtok(NULL, "	"));
        strcpy(address,strtok(NULL, "	"));
        strcpy(city,strtok(NULL, "	"));
        strcpy(state,strtok(NULL, "	"));

        if (Fchg32(f, FIRSTNAME, 0, f_name, 0) == -1) {
            fprintf(stderr, "Failure to change FIRSTNAME field -- %s\n", Fstrerror32(Ferror32));        
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        if (Fchg32(f, LASTNAME, 0, l_name, 0) == -1) {
            fprintf(stderr, "Failure to change LASTNAME field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        if (Fchg32(f, ADDRESS, 0, address, 0) == -1) {
            fprintf(stderr, "Failure to change ADDRESS field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        if (Fchg32(f, CITY, 0, city, 0) == -1) {
            fprintf(stderr, "Failure to change CITY field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

        if (Fchg32(f, STATE, 0, state, 0) == -1) {
            fprintf(stderr, "Failure to change STATE field -- %s\n", Fstrerror32(Ferror32));
            tpfree((char *)f);
            tpterm();
            exit(1);
        }

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

        /* Set QCTL structure options */
        qctl.msg_class = MSG_CLAS_EXAMPLES;
        qctl.msg_type = MSG_TYPE_CLIENT_REQ;
        qctl.block = del_mode;
        qctl.DIP = OTMQ_DIP_MEM;
        qctl.uma = OTMQ_UMA_RTS;
        qctl.timeout = 30;

        /* Enqueue to ZIPCODEFINDER TMQ queue */
        if (tpenqplus("QSPACE", "ZIPCODEFINDER", (TPQCTL *)&qctl, (char *)f, 0, 0) == -1)
        {
            fprintf(stderr, "Failure to enqueue ZIPCODEFINDER service -- %s \n", tpstrerror(tperrno));
            if (tperrno == TPEDIAGNOSTIC)
            {
                print_diagnostic(qctl.diagnostic);
            }
            tpfree((char *) f);
            tpabort(0);
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
    }  /*end while loop*/

    printf("\n *** Successful Enqueuing of 10 customer records ***\n");
    tpqexit();
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

