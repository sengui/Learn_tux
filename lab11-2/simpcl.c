/*------------------------------------------------------------------------
  -- DISCLAIMER:
  --    This script is provided for educational purposes only. It is NOT
  --    supported by Oracle World Wide Technical Support.
  --    The script has been tested and appears to work as intended.
  --    You should always run new scripts on a test instance initially.
  -- 
  ------------------------------------------------------------------------*/

#include <stdio.h>
#include "atmi.h"		/* TUXEDO  Header File */
#include <unistd.h>
#include <string.h>

#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
    TPINIT *tpinfop;
    char *sendbuf, *rcvbuf;
    long sendlen, rcvlen;
    int ret;

    if(argc != 2) {
        (void) fprintf(stderr, "Usage: simpcl string\n");
        exit(1);
    }

    /* Allocate a TPINIT buffer */
    if ((tpinfop = (TPINIT *)tpalloc("TPINIT", NULL, sizeof(struct tpinfo_t))) == NULL) {
        printf("ERROR: tpalloc failed (%s)\n", tpstrerror(tperrno));
        exit(1);
    }

    /* Enter user information */
    strcpy(tpinfop->usrname, "Logan");
    strcpy(tpinfop->cltname, "version_client");
    //strcpy(tpinfop->grpname, "APPGRP2");
    strcpy(tpinfop->passwd, "none");
    tpinfop->flags = 0;
    tpinfop->datalen = 0;
    tpinfop->data = 0;

    /* Attach to System/T as a Client Process */
    if (tpinit(tpinfop) == -1) {
        (void) fprintf(stderr, "Tpinit failed\n");
        exit(1);
    }

    sendlen = strlen(argv[1]);

    /* Allocate STRING buffers for the request and the reply */

    if((sendbuf = (char *) tpalloc("STRING", NULL, sendlen+1)) == NULL) {
        (void) fprintf(stderr,"Error allocating send buffer\n");
        tpterm();
        exit(1);
    }

    if((rcvbuf = (char *) tpalloc("STRING", NULL, sendlen+1)) == NULL) {
        (void) fprintf(stderr,"Error allocating receive buffer\n");
        tpfree(sendbuf);
        tpterm();
        exit(1);
    }

    (void) strcpy(sendbuf, argv[1]);

    /* Request the service TOUPPER, waiting for a reply */
    ret = tpcall("TOUPPER", (char *)sendbuf, 0, (char **)&rcvbuf, &rcvlen, (long)0);

    if(ret == -1) {
        (void) fprintf(stderr, "Can't send request to service TOUPPER\n");
        (void) fprintf(stderr, "Tperrno = %d\n", tperrno);
        tpfree(sendbuf);
        tpfree(rcvbuf);
        tpterm();
        exit(1);
    }

    (void) fprintf(stdout, "Returned string is: %s\n", rcvbuf);

    /* Free Buffers & Detach from System/T */
    tpfree(sendbuf);
    tpfree(rcvbuf);
    tpterm();
    return(0);
}
