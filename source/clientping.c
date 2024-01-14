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
 *  "clientping.c"
 *  "Version 1.1"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atmi.h"

static void
#if defined(__STDC__) || defined(__cplusplus)
print_err(FILE *out_or_err, char *err_str)
#else
print_err(out_or_err, err_str)
	char	*err_str;
	FILE	*out_or_err;
#endif
{
	(void)userlog(err_str);
	(void)fprintf(out_or_err, strcat(err_str, "\n"));
	return;
}

static void
#if defined(__STDC__) || defined(__cplusplus)
usage(char *name)
#else
usage(name)
     char *name;
#endif
{
	(void)fprintf(stderr, "Usage: %s\n", name);
	return;
}

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
	 int argc;
	 char *argv[];
#endif /* __STDC__ || __cplusplus */
{

	int	detail_val;
	char	err_str[160];
	int	exit_value;
	char	*io_buf;
	long	io_len;
	int	ret_value;
	int	tperrno_val;

	/*
	 * Check to make sure that the proper number of parameters were
	 * passed in.
	*/
	if (argc != 1) {
		usage(argv[0]);
		exit(1);
	}

	/*
	 * Allocate the buffer used to pass data between the client and
	 * the server.
	*/
	io_buf = (char *)tpalloc("STRING", NULL, 2048);
	if (io_buf == NULL) {
		(void)sprintf(err_str,
			"Allocation of io_buf failed, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		exit(1);
	}

	/*
	 * Loop forever.
	*/
	while (1) {
		/*
		 * Call tpinit() to attach to the application.
		*/
		ret_value = tpinit((TPINIT *) NULL);
		if (ret_value == -1) {
			(void)sprintf(err_str,
				"tpinit failed, error = %d: %s",
				tperrno, tpstrerror(tperrno));
			print_err(stderr, err_str);
			tpfree((char *)io_buf);
			exit(1);
		}

		exit_value = 0;
		while (!exit_value) {
			/*
			 * Request the service, waiting for a reply.
			*/
			ret_value = tpcall("SVC_PING", io_buf, 0, &io_buf, &io_len, (long)0);
			if (ret_value == -1) {
				tperrno_val = tperrno;
				detail_val = tperrordetail(0);
				/*
				 * Lost the connection to the WSH.
				*/
				if (tperrno_val == TPESYSTEM &&
					detail_val == TPED_TERM) {
					(void)sprintf(err_str,
						"Lost connection to WSH, reconnecting ...");
					print_err(stderr, err_str);
					exit_value = 1;
				}
				else {
					(void)sprintf(err_str,
						"Request for service SVC_PING failed, error = %d: %s",
						tperrno_val,
						tpstrerror(tperrno_val));
					print_err(stderr, err_str);
					(void)tpterm();
					exit(1);
				}
			}
			else {
				(void)printf(
					"\n%s", io_buf);
				//(void)sleep(2);
			}
		}

		/*
		 * Detach from the application.
		*/
		(void)tpterm();
	}

	/*
	 * Free Buffer
	*/
	tpfree(io_buf);
	return(0);
}
