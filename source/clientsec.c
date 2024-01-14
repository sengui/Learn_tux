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
 *  "clientsec.c"
 *  "Version 1.1"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ncurses.h>
/*
#include <iostream.h>
#include <conio.h>
*/
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

// Utility function used to prompt for passwords
// This utility uses the ncurses library functions to hide the typed password
void GetPass(char *promptstr, char *answer, size_t siz)
{
	cbreak();	/* Line buffering disabled */
	noecho();	/* Don't echo while we do getch */
	size_t i = 0;
	int key = 0;
	int endloop = 0;
	printw(promptstr);
	refresh();
	while (siz-- != 0) {
		if (endloop != 0) break;
		key = getch();   
		switch (key) {
			case '\0':
				answer[i] = key;
			default:
				answer[i] = key;
				printw("*");
				refresh();
				++i;
				break;
			case '\r':
			case '\n':
				answer[i] = '\0';
				endloop = 1;
				break;
		}
	}
	echo();		/* Turn on echo again */
	nocbreak();	/* Line buffering enabled again */
	refresh();

}// end GetPass()

/*
 * Prompt for a user ID and password, then pass that information to the system via tpinit().
 * Once connected to the application, call the GETAPPKEY service and display the returned APPKEY.
*/
int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
	int			argc;
	char			*argv[];
#endif /* __STDC__ || __cplusplus */
{

	char		err_str[180];
	int			exit_code = 0;
	TPINIT		*init_buf;
	char		app_password[31] = "";
	char		user_password[31] = "";
	int			ret_value;
	char		*io_buf;
	char		user_name[31] = "";
	long		rcv_len;



	/*
	 * Check to make sure that the proper number of parameters were
	 * passed in.
	*/
	if (argc > 1) {
		usage(argv[0]);
		exit(1);
	}

	/*
	 * Prompt for the user name and passwords
	*/
	initscr();	/* Start ncurses mode */
	while (strlen(app_password) == 0) {
//		printf("Application Password: ");
//		scanf("%s", app_password);
		printw("\n");
		refresh();
		GetPass("Enter password to access Tuxedo domain: ", app_password, 12);
	}
	while (strlen(user_name) == 0) {
		echo();
		printw("\nEnter your user name: ");
		refresh();
		scanw("%s", user_name);
	}
	while (strlen(user_password) == 0) {
//		printf("User Password: ");
//		scanf("%s", user_password);
		GetPass("Enter user password: ", user_password, 13);
	}
	endwin();	/* End ncurses mode */

	/*
	 * Allocate the TPINIT buffer and populate it.
	 * Call tpinit() to attach to the application.
	*/
	init_buf = (TPINIT *)tpalloc("TPINIT", NULL,
		(long)(sizeof(TPINIT) + strlen(user_password) +1));
	if (init_buf == NULL) {
		(void)sprintf(err_str,
			"Allocation of TPINIT buffer failed, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		exit(1);
	}
	(void)strcpy(init_buf->usrname, user_name);
	(void)strcpy(init_buf->passwd, app_password);
	(void)strcpy((char *)&init_buf->data, user_password);

	ret_value = tpinit(init_buf);
	if (ret_value == -1) {
		(void)sprintf(err_str,
			"Failed to attach to the application, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		exit(1);
	}
	(void)printf("Successful tpinit\n");
	tpfree((char *)init_buf);

	/*
	 * Allocate the buffer used to pass data between client and server.
	 * Because we are not sending any data in, we only need one buffer.
	*/
	(void)printf("Calling GETAPPKEY\n");
	/*
	 * Allocate the buffer used to pass data between client and server.
	 * Because we are not sending any data in, we only need one buffer.
	*/
	io_buf = (char *)tpalloc("STRING", NULL, 12);
	if (io_buf == NULL) {
		(void)sprintf(err_str,
			"Allocation of io_buf failed, error = %d: %s",
			tperrno, tpstrerror(tperrno));
		print_err(stderr, err_str);
		exit_code = 1;
	}
	else {
		/*
		 * Call the server and display the resulting APPKEY.
		*/
		if (tpcall("GETAPPKEY", io_buf, 0, &io_buf, &rcv_len, TPSIGRSTRT) == -1) {
//			(void)sprintf(err_str,
//				"Call to GETAPPKEY failed, error = %d: %s",
//				tperrno, tpstrerror(tperrno));
//			print_err(stderr, err_str);
			(void)printf("Could not retrieve APPKEY - Service Access Denied\n");
			exit_code = 1;
		}
		else {
			(void)printf("APPKEY = %s\n", io_buf);
		}
	}
	tpfree(io_buf);
	(void)tpterm();
	return(exit_code);
}
