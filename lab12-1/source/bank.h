/*	
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 */
#ifndef NOWHAT
static	char	h_bank[] = "@(#) samples/atmi/bankapp/bank.h	$Revision: 1.5 $";
#endif


#ifndef BANK_H
#define	BANK_H

/*  The following keywords give mnemonics to various banking functions  */

#define DAPB 		10	/* accounts per branch default*/
#define DTPB 1
#define STATLEN 	80	/* length of string for status line */
#define NAMELEN		16	/* length of service names */
#define PRIORITY	40	/* message priority increase value */
#define MAXBRANCH 	10	/* number of bank branches */
#define MINACCT		10000L 	/* smallest account number */
#define MAXACCT		120000L	/* largest account number  */
#define BALSTR		12	/* length of amount strings*/

/*
 * Branch representatives for each machine.  The system administrator
 * must set this array so that one branch id from each machine, appears.
 * This enables clients to send requests to all machines by branch id.
 */

/* #define SITEREP { 1 } */

#define SITEREP { 1, 5, 8 }

/*
 * Number of machines in system.  The system administrator must set this
 * to the number of machines in the configuration.
 */

/* #define NSITE 1 */

#define NSITE 3

#undef _
#if defined(__STDC__) || defined(__cplusplus) || defined(_as400_)
#define _(a) a
#else
#define _(a) ()
#endif

char	*getstr _((char *, long));
char	*gettime _((void));

/* Unix functions not in header files */
#ifndef __SGIDEFS_H__
extern	long nrand48 _((unsigned short []));
extern	unsigned short *seed48 _((unsigned short []));
#if defined(WIN32) || defined(_as400_)
extern char *getpass(const char *);
#else
extern	void srand _((unsigned));
extern	int rand _((void));
#endif
#endif

#endif
