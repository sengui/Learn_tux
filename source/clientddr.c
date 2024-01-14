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
 *  "clientddr.c"
 *  "Version 1.1"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atmi.h"
#include "userlog.h"
#include "fml32.h"
#include "ddr32fml.h"

#define NUM_FIELDS 4
#define FML_LEN (3 * sizeof(float) + sizeof(long))

#ifdef WIN32
#define PATH_DELIMITER         '\\'
#else
#define PATH_DELIMITER         '/'
#endif /* WIN32 */

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
main (argc, argv)
	int argc;
	char *argv[];
#endif
{
	char	err_str[160];
	FBFR32	*bufptr;
	float	amount;
	long	from_acct, to_acct;
	long	len;
	char	*program_name;
	float	from_start, from_end;
	float	to_start, to_end;

	/*
	 * Check the usage.
	*/
		if (argc != 1) {
		(void)usage(argv[0]);
		exit(1);
	}

	/*
	* Set the external variable proc_name (defined in userlog.h)
	* to be the name of the executable program so that it appears
	* in the Tuxedo ULOG entries for the client program.
	*/

	program_name = strrchr(argv[0], PATH_DELIMITER);
	if (program_name == NULL) {
		proc_name = argv[0];
	}
	else {
		proc_name = &program_name[1];
	}

	/*
	 * Join the application and allocate the buffer.
	*/
		if (tpinit((TPINIT *)NULL) == -1) {
		(void)sprintf(err_str,
			"Client failed to join the application, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)exit(1);
	}

	if ((bufptr = (FBFR32 *)tpalloc("FML32", NULL,
		Fneeded32(NUM_FIELDS, FML_LEN))) == NULL) {
		(void)sprintf(err_str,
			"Client failed to allocate the FML buffer, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpterm();
		(void)exit(1);
	}

	/*
	 * Get the values from the user and add them to the FML buffer.
	*/
	(void)fprintf(stdout, "TRANSFER\n");
	(void)fprintf(stdout, "Enter the account to transfer from: ");
	(void)scanf("%ld", &from_acct);
	(void)fprintf(stdout, "Enter the account to transfer to: ");
	(void)scanf("%ld", &to_acct);
	(void)fprintf(stdout, "Enter the amount to transfer: ");
	(void)scanf("%f", &amount);
	if (Fchg32(bufptr, AMOUNT, 0, (char *)&amount, 0) == -1) {
		(void)sprintf(err_str,
			"Fadd32 failed for AMOUNT, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fchg32(bufptr, ACCOUNT, 0, (char *)&from_acct, 0) == -1) {
		(void)sprintf(err_str,
			"Fadd32 failed for first account, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}

    fprintf(stdout, "Transferring $%f from account %d to account %d.\n", amount, from_acct, to_acct);
	/*
	 * Call the WITHDRAW service.
	*/
	if (tpcall("WITHDRAW", (char *)bufptr, 0,(char **)&bufptr, &len,
			   TPSIGRSTRT) == -1) {
		(void)sprintf(err_str,
			"Service WITHDRAW failed, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)fprintf(stderr, "See the USERLOG for messages from the server.\n");
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fget32(bufptr, START_BAL, 0, (char *)&from_start, NULL) == -1) {
		(void)sprintf(err_str,
			"Client failed get the starting balance from the first account, error = %d: %s",
			Ferror32, Fstrerror32(Ferror32));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fget32(bufptr, END_BAL, 0, (char *)&from_end, NULL) == -1) {
		(void)sprintf(err_str,
			"Client failed get the ending balance from the first account, error = %d: %s",
			Ferror32, Fstrerror32(Ferror32));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fchg32(bufptr, ACCOUNT, 0, (char *)&to_acct, 0) == -1) {
		(void)sprintf(err_str,
			"Fadd32 failed for second account, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (tpcall("DEPOSIT", (char *)bufptr, 0,(char **)&bufptr, &len,
		TPSIGRSTRT) == -1) {
		(void)sprintf(err_str,
			"Service DEPOSIT failed, error = %d: %s", tperrno,
			tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)fprintf(stderr, "See the USERLOG for messages from the server.\n");
		/*
		 * 	Restore the amount withdrawn from the first account.
		*/
		if (Fchg32(bufptr, ACCOUNT, 0, (char *)&from_acct, 0) == -1) {
			(void)sprintf(err_str,
				"Fadd32 failed for first account, error = %d: %s",
				tperrno, tpstrerror(tperrno));
			print_err(stderr, err_str);
			(void)tpfree((char *)bufptr);
			(void)tpterm();
			(void)exit(1);
		}
		if (tpcall("DEPOSIT", (char *)bufptr, 0,(char **)&bufptr, &len,
				   TPSIGRSTRT) == -1) {
			(void)sprintf(err_str,
				"Client failed to restore amount to first account, error = %d: %s",
				tperrno, tpstrerror(tperrno));
			print_err(stderr, err_str);
			(void)fprintf(stderr, "See the USERLOG for messages from the server.\n");
			(void)tpfree((char *)bufptr);
			(void)tpterm();
			(void)exit(1);
		}
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fget32(bufptr, START_BAL, 0, (char *)&to_start, NULL) == -1) {
		(void)sprintf(err_str,
			"Client failed get the starting balance from the second account, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}
	if (Fget32(bufptr, END_BAL, 0, (char *)&to_end, NULL) == -1) {
		(void)sprintf(err_str,
			"Client failed get the ending balance from the second account, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		(void)tpfree((char *)bufptr);
		(void)tpterm();
		(void)exit(1);
	}

	(void)printf("Transfer successful.\n");
	(void)printf("Account %d: Beginning balance = %.2f, Ending balance = %.2f\n",
		from_acct, from_start, from_end);
	(void)printf("Account %d: Beginning balance = %.2f, Ending balance = %.2f\n",
		to_acct, to_start, to_end);
	(void)tpfree((char *)bufptr);
	(void)tpterm();
	(void)exit(0);
}
