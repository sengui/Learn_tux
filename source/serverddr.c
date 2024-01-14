/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 *  "Data-Dependent Routing Lab"
 *  "serverddr.c"
 *  "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "atmi.h"
#include "userlog.h"
#include "fml32.h"
#include "ddr32fml.h"
#include "Uunix.h"

struct acct_info {
	long	acct_id;
	float	balance;
} acct_data[10];

int
#if defined(__STDC__) || defined(__cplusplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
	int	argc;
	char	**argv;
#endif
{
	FILE	*file;
	int		error;
	int		counter;

	/*
	 * Write an initialization message to the user log.
	*/
	userlog("Initializing %s.", argv[0]);
	/*
	 * Read the account data from the data file.
	*/
	(void)getopt(argc, argv, "f:");
	file = fopen(optarg, "r");
	if (file == NULL) {
		(void)userlog("Cannot open file %s, Error: %s\n", optarg,
			strerror(errno));
		return(-1);
	}
	for (counter = 0; counter < 10; counter++) {
		if ((error = (fscanf(file, "%ld%f", &acct_data[counter].acct_id,
			&acct_data[counter].balance))) != 2) {
			error = errno;
			(void)userlog("Error reading file %s, Error: %s\n", optarg,
				strerror(error));
			(void)fclose(file);
			return(-1);
		}
	}
	fclose(file);

	return(0);
}

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
DEPOSIT(TPSVCINFO *call_buf)
#else
DEPOSIT(call_buf)
	TPSVCINFO	*call_buf;
#endif
{

	FBFR32	*pfmlbuf;
	long	acct_id;
	long	len;
	float	amount;
	int		counter;

	pfmlbuf = (FBFR32 *)call_buf->data;

	if (Fget32(pfmlbuf, ACCOUNT, 0, (char *)&acct_id, NULL) == -1) {
		(void)userlog("DEPOSIT: Error accessing account ID in input buffer, Ferror32 = %d:%s.\n",
			Ferror32, Fstrerror32(Ferror32));
	} else {
		if (Fget32(pfmlbuf, AMOUNT, 0, (char *)&amount, NULL) == -1) {
			(void)userlog("DEPOSIT: Error accessing amount in input buffer, Ferror32 = %d:%s.\n",
				Ferror32, Fstrerror32(Ferror32));
		} else {
			for (counter = 0; counter < 10; counter++) {
				if (acct_id == acct_data[counter].acct_id) {
					break;
				}
			}
			if (counter == 10) {
				(void)userlog("ERROR: Information for account %ld is not available on this server.",
						acct_id);
			} else {
				if (Fchg32(pfmlbuf, START_BAL, 0,
					(char *)&acct_data[counter].balance, 0) == -1) {
					(void)userlog("DEPOSIT: Error updating starting balance, Ferror32 = %d:%s.\n",
						Ferror32, Fstrerror32(Ferror32));
				} else {
					amount += acct_data[counter].balance;
					if (Fchg32(pfmlbuf, END_BAL, 0,
						(char *)&amount, 0) == -1) {
						(void)userlog("DEPOSIT: Error updating ending balance, Ferror32 = %d:%s.\n",
							Ferror32, Fstrerror32(Ferror32));
					} else {
						acct_data[counter].balance = amount;
						tpreturn(TPSUCCESS, 0, (char *)pfmlbuf, 0L, 0);
					}
				}
			}
		}
	}
	tpreturn(TPFAIL, tperrno, (char *)pfmlbuf, 0L, 0);
}

#ifdef __cplusplus
extern "C"
#endif
void
#if defined(__STDC__) || defined(__cplusplus)
WITHDRAW(TPSVCINFO *call_buf)
#else
WITHDRAW(call_buf)
	TPSVCINFO	*call_buf;
#endif
{

	FBFR32	*pfmlbuf;
	long	acct_id;
	long	len;
	float	amount;
	int		counter;

	pfmlbuf = (FBFR32 *)call_buf->data;

	if (Fget32(pfmlbuf, ACCOUNT, 0, (char *)&acct_id, NULL) == -1) {
		(void)userlog("WITHDRAW: Error accessing account ID in input buffer, Ferror32 = %d:%s.\n",
			Ferror32, Fstrerror32(Ferror32));
	} else {
		if (Fget32(pfmlbuf, AMOUNT, 0, (char *)&amount, NULL) == -1) {
			(void)userlog("WITHDRAW: Error accessing amount in input buffer, Ferror32 = %d:%s.\n",
				Ferror32, Fstrerror32(Ferror32));
		} else {
			for (counter = 0; counter < 10; counter++) {
				if (acct_id == acct_data[counter].acct_id) {
					break;
				}
			}
			if (counter == 10) {
				(void)userlog("ERROR: Information for account %ld is not available on this server.",
						acct_id);
			} else {
				if (Fchg32(pfmlbuf, START_BAL, 0,
					(char *)&acct_data[counter].balance, 0) == -1) {
					(void)userlog("WITHDRAW: Error updating starting balance, Ferror32 = %d:%s.\n",
						Ferror32, Fstrerror32(Ferror32));
				} else {
					amount = acct_data[counter].balance - amount;
					if (Fchg32(pfmlbuf, END_BAL, 0,
						(char *)&amount, 0) == -1) {
						(void)userlog("WITHDRAW: Error updating ending balance, Ferror32 = %d:%s.\n",
							Ferror32, Fstrerror32(Ferror32));
					} else {
						acct_data[counter].balance = amount;
						tpreturn(TPSUCCESS, 0, (char *)pfmlbuf, 0L, 0);
					}
				}
			}
		}
	}
	tpreturn(TPFAIL, tperrno, (char *)pfmlbuf, 0L, 0);
}
