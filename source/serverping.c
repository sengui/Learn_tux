/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 *  "Redundancy Configuration Lab"
 *  "serverping.c"
 *  "Version 1.1"
*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "atmi.h"
#include "fml32.h"
#include "tpadm.h"
#include "userlog.h"

static char	ping_data[80];

int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
	int	argc;
	char	**argv;
#endif
{
	FBFR32	 *mibbuf;
	long	 pid;
	long	 srvid;
	long	 miblen;
	long	 flags;
	char	 lmid[MAXTIDENT+1];
	char	 group[MAXTIDENT+1];
	FLDLEN32 str_len;

	/*
	 * The following two lines prevent warning messages from lint and
	 * some compilers.
	*/
	argc = argc;
	argv = argv;

	/*
	 * Write an initialization message to the user log.
	*/
	(void)userlog("Initializing %s.", argv[0]);

	/*
	 * Allocate the buffer.
	*/
	mibbuf = (FBFR32 *)tpalloc("FML32", NULL, 4000);
	/*
	 * Retrieve the process ID and server ID.
	*/
	(void)Fchg32(mibbuf, TA_OPERATION, 0, "GET", 0);
	(void)Fchg32(mibbuf, TA_CLASS, 0, "T_SERVER", 0);
	flags = MIB_LOCAL | MIB_SELF;
	(void)Fchg32(mibbuf, TA_FLAGS, 0, (char *)&flags, 0);
	(void)tpcall(".TMIB", (char *)mibbuf, 0L, (char **)&mibbuf, &miblen,
		0L);
	(void)Fget32(mibbuf, TA_PID, (FLDOCC32)0, (char *)&pid, NULL);
	(void)Fget32(mibbuf, TA_SRVID, (FLDOCC32)0, (char *)&srvid, NULL);
	str_len = MAXTIDENT+1;
	(void)Fget32(mibbuf, TA_LMID, (FLDOCC32)0, lmid, &str_len);
	str_len = MAXTIDENT+1;
	(void)Fget32(mibbuf, TA_SRVGRP, (FLDOCC32)0, group, &str_len);
	(void)sprintf(ping_data, "You have called: LMID=%s, Group=%s, SRVID=%ld, PID=%ld\n", lmid, group, srvid, pid);
	tpfree((char *)mibbuf);
	return(0);
}

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
PING(TPSVCINFO *call_buf)
#else
PING(call_buf)
	TPSVCINFO	*call_buf;
#endif
{
	char	*ping_string;

	ping_string = (char *)call_buf->data;
	strcpy(ping_string, ping_data);
	(void)sleep(2);
	tpreturn(TPSUCCESS, 0L, ping_string, 0L, 0L);
}
