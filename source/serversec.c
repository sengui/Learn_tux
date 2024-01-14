/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 *  "Security Lab"
 *  "serversec.c"
 *  "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include "atmi.h"
#include "userlog.h"

int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
	int	argc;
	char	**argv;
#endif
{
	/*
	 * The following two lines prevent warning messages from lint and
	 * some compilers.
	*/
	argc = argc;
	argv = argv;

	/*
	 * Write an initialization message to the user log.
	*/
	userlog("Initializing %s.", argv[0]);
	return(0);
}

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
GETAPPKEY(TPSVCINFO *call_buf)
#else
GETAPPKEY(call_buf)
	TPSVCINFO	*call_buf;
#endif
{

	(void)sprintf(call_buf->data, "%ld", call_buf->appkey);

	tpreturn(TPSUCCESS, 0L, call_buf->data, 0L, 0L);
}
