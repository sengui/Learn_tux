
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[8];
};
static const struct sqlcxp sqlfpn =
{
    7,
    "ACCT.pc"
};


static unsigned int sqlctx = 8459;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0001 = 
"select LAST_ACCT  from BRANCH where BRANCH_ID=:b0           ";

 static const char *sq0004 = 
"select BALANCE  from ACCOUNT where ACCOUNT_ID=:b0           ";

 static const char *sq0006 = 
"select SSN  from ACCOUNT where ACCOUNT_ID=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4128,1,27,0,
5,0,0,1,60,0,9,262,0,0,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,263,0,0,1,0,0,1,0,2,3,0,0,
43,0,0,1,0,0,15,266,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,269,0,0,0,0,0,1,0,
73,0,0,2,157,0,3,276,0,0,10,10,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,1,0,0,
1,97,0,0,1,97,0,0,1,1,0,0,1,97,0,0,1,97,0,0,
128,0,0,3,52,0,5,319,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
151,0,0,4,60,0,9,441,0,0,1,1,0,1,0,1,3,0,0,
170,0,0,4,0,0,13,442,0,0,1,0,0,1,0,2,4,0,0,
189,0,0,4,0,0,15,445,0,0,0,0,0,1,0,
204,0,0,4,0,0,15,448,0,0,0,0,0,1,0,
219,0,0,5,42,0,2,483,0,0,1,1,0,1,0,1,3,0,0,
238,0,0,6,56,0,9,527,0,0,1,1,0,1,0,1,3,0,0,
257,0,0,6,0,0,13,528,0,0,1,0,0,1,0,2,97,0,0,
276,0,0,6,0,0,15,531,0,0,0,0,0,1,0,
291,0,0,6,0,0,15,534,0,0,0,0,0,1,0,
};


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
static	char	sccsid[] = "@(#) samples/atmi/bankapp/ACCT.ec	$Revision: 1.5 $";
#endif

#include <stdio.h>		/* UNIX */
#include <string.h>		/* UNIX */
#ifdef _TMFML32
#include <fml32.h>		/* TUXEDO */
#include <fml1632.h>		/* TUXEDO */
#include <Usysfl32.h>		/* TUXEDO */
#else
#include <fml.h>		/* TUXEDO */
#include <Usysflds.h>		/* TUXEDO */
#endif
#include <atmi.h>		/* TUXEDO */

#include <userlog.h>		/* TUXEDO */
#include "bank.h"		/* BANKING #defines */
#include "bankflds.h"		/* bankdb fields */
#ifdef HOST
#include "creditflds.h"	/* creditdb fields */
#endif
#include "eventflds.h"		/* event fields */


/* EXEC SQL include sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


#define SQLCODE sqlca.sqlcode
#define SQL_OK  0


/* EXEC SQL begin declare section; */ 

static long   account_id;			/* account id */
static long   branch_id;			/* branch id */
static float  bal, tlr_bal;			/* BALANCE */
static char   acct_type;			/* account type */
static char   last_name[21], first_name[21];	/* last name, first name */
static char   mid_init;				/* middle initial */
static char   ss_n[12];				/* social security number */
static char   address[61];			/* address */
static char   phone[13];			/* telephone */
static long   last_acct;			/* last account branch gave */
/* EXEC SQL end declare section; */ 


static FBFR *reqfb;     	/* fielded buffer for request message */
static long reqlen;		/* length of request buffer */
static char amts[BALSTR];	/* string representation of float */

/* Event logic related */
static char 	emsg[200] ;	/* holds error message string */

/*
 * Service to open a new account
 */

void
#if defined(__STDC__) || defined(__cplusplus)
OPEN_ACCT(TPSVCINFO *transb)
#else
OPEN_ACCT(transb)
TPSVCINFO *transb;
#endif
{
	FBFR   *transf;	/* fielded buffer of decoded message */
	FLDLEN len;
    int ret;

    userlog("I'm in OPEN_ACCT service");

#ifdef HOST
	/* credit card account handling */
	int    opencr=0;	/* set to 1, if credit card account is openned*/
	char   vssn[12];	/* return ssn from VALDC call */
	float  svc_chg;		/* SVCHG*/
	char   svcchg[BALSTR];	/* string rep of SVCHG*/
	char   open_cr;		/* open a credit card? Y/N */
	char   c_acct_type;	/* credit card type */
	long   c_account_id=0L;	/* credit account id */
	float  c_bal=0.0; 	/* credit balance*/
	float  c_crt_line=0.0; 	/* credit line */
	char   cbal[11];
	char   ccrtline[11];
#endif

	/* set pointer to TPSVCINFO data buffer */

	transf = (FBFR *)transb->data;
	(void)Fchg(transf, STATLIN, 0, "", (FLDLEN)0);

	/* Get all values for service request from fielded buffer */

	/* must have opening balance */

	len = BALSTR;
	if (Fget(transf, SAMOUNT, 0, amts, &len) < 0 
		|| strcmp(amts,"") == 0) {
		(void)Fchg(transf, STATLIN, 0, "Invalid amount",(FLDLEN)0);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}
	(void)sscanf(amts,"%f",&bal);

	/* must have valid amount to deposit */
	if (bal <= 0.0) {
		(void)Fchg(transf, STATLIN, 0,
			"Initial deposit must be greater than $0.00",(FLDLEN)0);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}

	/* must have account type */
	len = sizeof(acct_type) ;
	if (Fget(transf, ACCT_TYPE, 0, &acct_type, &len) < 0) {
                (void)Fchg(transf, STATLIN, 0, 
			   "Invalid account type", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        } 
	len = sizeof(last_name);
	last_name[0] = '\0';
	(void)Fget(transf, LAST_NAME, 0, last_name, &len);

	len = sizeof(first_name);
	first_name[0] = '\0';
	(void)Fget(transf, FIRST_NAME, 0, first_name, &len);

	len = sizeof(mid_init);
	mid_init = '\0';
	(void)Fget(transf, MID_INIT, 0, &mid_init, &len);

	len = sizeof(address);
	address[0] = '\0';
	(void)Fget(transf, ADDRESS, 0, address, &len);

	len = sizeof(phone);
	phone[0] = '\0';
	(void)Fget(transf, PHONE, 0, phone, &len);

	len = sizeof(ss_n);
	ss_n[0] = '\0';
	(void)Fget(transf, SSN, 0, ss_n, &len);

	/* must have branch id */
	if (((branch_id = (long)Fvall(transf, BRANCH_ID, 0)) <= 0L) || 
	    (branch_id > MAXBRANCH)) {
		(void)Fchg(transf, STATLIN, 0, "Invalid branch id", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}

#ifdef HOST
	cbal[0] = '\0';
	ccrtline[0] = '\0';

	/* check if want to open a credit card?*/
	len = sizeof(open_cr);
	(void)Fget(transf, OPEN_CR, 0, &open_cr, &len);
	if (open_cr == 'y' || open_cr == 'Y') {
		/* get credit card account type */
		if (Fget(transf, C_ACCT_TYPE, 0, &c_acct_type,&len) < 0) {
                	(void)Fchg(transf, STATLIN, 0, 
			   "Invalid credit card account type", (FLDLEN)0);
                	tpreturn(TPFAIL, 0, transb->data, 0L, 0);
		}

		/* allocate the buffer for OPENC request */
		if ((reqfb = (FBFR *)tpalloc(FMLTYPE,NULL,transb->len)) 
			== (FBFR *)NULL) {
			(void)userlog("tpalloc failed in open_acct\n");
			(void)Fchg(transf, STATLIN, 0,
				"Unable to allocate request buffer", 
				(FLDLEN)0);
			tpreturn(TPFAIL, 0, transb->data, 0L, 0);
		}
		reqlen = Fsizeof(reqfb);

		(void)Fchg(reqfb, LAST_NAME, 0,last_name, (FLDLEN)0);
		(void)Fchg(reqfb, FIRST_NAME, 0,first_name, (FLDLEN)0);
		(void)Fchg(reqfb, MID_INIT, 0,&mid_init, (FLDLEN)0);
		(void)Fchg(reqfb, ADDRESS, 0,address, (FLDLEN)0);
		(void)Fchg(reqfb, SSN, 0,ss_n, (FLDLEN)0);
		(void)Fchg(reqfb, PHONE, 0,phone, (FLDLEN)0);
		(void)Fchg(reqfb, C_ACCT_TYPE, 0,&c_acct_type, (FLDLEN)0);
		(void)Fchg(reqfb, VIEWNAME, 0,"open_cro", (FLDLEN)0);

		/* increase the priority of withdraw call */
		if (tpsprio(PRIORITY, 0L) == -1)
			(void)userlog("Unable to increase priority of withdraw\n");

		/* make the service request call */
		if (tpcall("OPENC", (char *)reqfb, 0L, (char **)&reqfb, 
			(long *)&reqlen, TPNOTRAN) < 0 ) {
			opencr = 0;
			(void)Fchg(transf, STATLIN, 0, 
			   "Unable to open the credit card currently",(FLDLEN)0);
		}
		else {
			opencr = 1;
			c_account_id = (long)Fvall(reqfb,C_ACCOUNT_ID,0);
			(void)Fget(reqfb, C_BAMOUNT, 0, cbal, 0);
			(void)Fget(reqfb, C_CAMOUNT, 0, ccrtline, 0);
		}
		tpfree((char *)reqfb);
        }

	svc_chg = 0.0;
	/* If open a checking account, do a credit reference checking. 
	 * If no credit reference, service charge of $1.00.
	 * If good credit reference, service charge is waived. */
	if ((acct_type == 'c' || acct_type == 'C') && !opencr) {
		if ((reqfb = (FBFR *)tpalloc(FMLTYPE,NULL,transb->len)) 
			== (FBFR *)NULL) {
			(void)userlog("tpalloc failed in open_acct\n");
			(void)Fchg(transf, STATLIN, 0,
				"Unable to allocate request buffer", 
				(FLDLEN)0);
			tpreturn(TPFAIL, 0, transb->data, 0L, 0);
		}
		reqlen = Fsizeof(reqfb);
		(void)Finit(reqfb,(int)reqlen);

		/* put SSN in request buffer */
		(void)Fchg(reqfb, SSN, 0,ss_n, (FLDLEN)0);
		(void)Fchg(reqfb, VIEWNAME, 0,"vald_cr", (FLDLEN)0);

		/* put C_ACCOUNT_ID in request buffer */
		(void)Fadd(reqfb, C_ACCOUNT_ID,(char *)&c_account_id, (FLDLEN)0);

		/* increase the priority of withdraw call */
		if (tpsprio(PRIORITY, 0L) == -1)
			(void)userlog("Unable to increase priority of withdraw\n");
		/* make the service request call */
		if ((tpcall("VALDC", (char *)reqfb, 0L, (char **)&reqfb, 
			(long *)&reqlen, TPNOTRAN) < 0 ) ||
			(Fvall(reqfb, C_ACCOUNT_ID, 0) == 0) ||
			(Fvals(reqfb, SSN, 0) == NULL) ||
			(strcmp(Fvals(reqfb, SSN, 0),"000-00-0000")== 0 )) {
			bal -= 1.0;
			svc_chg = 1.0;
			if (bal <= 0.0) {
				(void)Fchg(transf, STATLIN, 0,
"No credit reference, initial depost must be greater than $1.01",0);
				tpreturn(TPFAIL, 0, transb->data, 0L, 0);
			}

		}
		tpfree((char *)reqfb);
	}  /* if open a checking account */
	(void)sprintf(svcchg,"$%.2f",svc_chg);
#endif

	/* retrieve LAST ACCOUNT number for this branch */
	/* EXEC SQL declare ocur cursor for
		select LAST_ACCT from BRANCH where BRANCH_ID = :branch_id; */ 

	/* EXEC SQL open ocur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&branch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL fetch ocur into :last_acct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&last_acct;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* nothing found */
		(void)Fchg(transf, STATLIN, 0, getstr("branch",SQLCODE), (FLDLEN)0);
		/* EXEC SQL close ocur; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )43;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

		/* close cursor */
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}
	/* EXEC SQL close ocur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )58;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

			/* close if not already closed */

    /* Insert new account record into ACCOUNT*/

    account_id = ++last_acct; 		/* get new account number */
	tlr_bal = 0.0;				/* temporary balance of 0 */

	/* EXEC SQL insert into ACCOUNT (ACCOUNT_ID, BRANCH_ID, SSN, BALANCE,
		ACCT_TYPE, LAST_NAME, FIRST_NAME, MID_INIT, ADDRESS, PHONE) 
	values
		(:account_id, :branch_id, :ss_n, :tlr_bal, :acct_type,
		 :last_name, :first_name, :mid_init, :address, :phone); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into ACCOUNT (ACCOUNT_ID,BRANCH_ID,SSN,BALANCE,ACCT_T\
YPE,LAST_NAME,FIRST_NAME,MID_INIT,ADDRESS,PHONE) values (:b0,:b1,:b2,:b3,:b4,:\
b5,:b6,:b7,:b8,:b9)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&account_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&branch_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)ss_n;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&tlr_bal;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(float);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&acct_type;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)last_name;
 sqlstm.sqhstl[5] = (unsigned long )21;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)first_name;
 sqlstm.sqhstl[6] = (unsigned long )21;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&mid_init;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)address;
 sqlstm.sqhstl[8] = (unsigned long )61;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)phone;
 sqlstm.sqhstl[9] = (unsigned long )13;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* Failure to insert */
		(void)Fchg(transf, STATLIN, 0, 
			"Cannot update ACCOUNT", (FLDLEN)0);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}

    /* allocate the buffer for SSNACCT_ADD request */
if (acct_type == 'S') {
    if ((reqfb = (FBFR *)tpalloc(FMLTYPE,NULL,transb->len)) 
        == (FBFR *)NULL) {
        (void)userlog("tpalloc failed in open_acct\n");
        (void)Fchg(transf, STATLIN, 0,
            "Unable to allocate request buffer", 
            (FLDLEN)0);
        tpreturn(TPFAIL, 0, transb->data, 0L, 0);
    }
    reqlen = Fsizeof(reqfb);
    Finit(reqfb, (FLDLEN)reqlen);

    (void)Fchg(reqfb, SSN, 0, ss_n, (FLDLEN)0);
/* original code:
    (void)Fchg(reqfb, SSN, 0, (char **)&ss_n, (FLDLEN)0);
*/
    (void)Fchg(reqfb, ACCOUNT_ID, 0, (char *)&account_id, (FLDLEN)0);

    /* Call the SSNACCT_ADD service to insert record in SSNACCT table */
    if (tpcall("SSNACCT_ADD", (char *)reqfb, 0L, (char **)&reqfb, 
        (long *)&reqlen, TPSIGRSTRT) < 0 ) {
        userlog("Call SSNACCT_ADD error: %d - %s",tperrno, tpstrerror(tperrno));
        (void)Fchg(transf, STATLIN, 0, 
           "Unable to call the SSNACCT_ADD service in open acct",(FLDLEN)0);
        tpreturn(TPFAIL, 0, transb->data, 0L, 0);
    }
    tpfree((char *)reqfb);
}

	/* Update branch record with new LAST_ACCT */

	/* EXEC SQL update BRANCH set LAST_ACCT = :last_acct
		where BRANCH_ID = :branch_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update BRANCH  set LAST_ACCT=:b0 where BRANCH_ID=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )128;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&last_acct;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&branch_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* Failure to update */
		(void)Fchg(transf, STATLIN, 0,"Cannot update BRANCH", (FLDLEN)0);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}

	
	/* tpcall to deposit service to add amount of initial balance */

	/* make deposit request buffer */
        if ((reqfb = (FBFR *)tpalloc(FMLTYPE,NULL,transb->len)) == (FBFR *)NULL) {
                (void)userlog("tpalloc failed in open_acct\n");
                (void)Fchg(transf, STATLIN, 0, 
			   "Unable to allocate request buffer", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        }
        reqlen = Fsizeof(reqfb);
        (void)Finit(reqfb,(FLDLEN)reqlen);

	/* put ID in request buffer */
        (void)Fchg(reqfb,ACCOUNT_ID,0,(char*)&account_id, (FLDLEN)0);

	/* put amount into request buffer */
	(void)sprintf(amts,"%.2f",bal);
	(void)Fchg(reqfb,SAMOUNT,0,amts, (FLDLEN)0);


	/* increase the priority of the deposit call */
	if (tpsprio(PRIORITY, 0L) == -1)
		(void)userlog("Unable to increase priority of deposit\n");

	if (tpcall("DEPOSIT", (char *)reqfb, 0L, (char **)&reqfb, (long *)&reqlen,
 		   TPSIGRSTRT) == -1) {
		(void)Fchg(transf, STATLIN, 0, 
			   "Cannot make deposit into new account", (FLDLEN)0);
		tpfree((char *)reqfb);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        }


	/* prepare buffer for successful return */
	(void)Fchg(transf, SBALANCE, 0, Fvals(reqfb,SAMOUNT,0), (FLDLEN)0);
	(void)Fchg(transf, ACCOUNT_ID, 0, (char *)&account_id, (FLDLEN)0);
	(void)Fchg(transf, FORMNAM, 0, "COPEN", (FLDLEN)0);
#ifdef HOST
	(void)Fchg(transf, SVCHG, 0, (char *)svcchg, (FLDLEN)0);
	(void)Fchg(transf, C_BAMOUNT, 0, (char *)cbal, (FLDLEN)0);
	(void)Fchg(transf, C_CAMOUNT, 0, (char *)ccrtline, (FLDLEN)0);
	(void)Fchg(transf, C_ACCOUNT_ID, 0,(char *)&c_account_id, (FLDLEN)0);
#endif
	tpfree((char *)reqfb);

	/* Post a BANK_CTR_OPENACCT event */

	/* initialize error message string */
	(void)strcpy (emsg, "") ;

	/* add event related fields */
	if ((Fchg (transf, EVENT_NAME, 0, "BANK_CTR_OPENACCT", (FLDLEN)0) == -1) ||
	    (Fchg (transf, EVENT_TIME, 0, gettime(), (FLDLEN)0) == -1) ||
	    (Fchg (transf, AMOUNT, 0, (char *)&bal, (FLDLEN)0) == -1)) {

		(void)sprintf (emsg, "Fchg failed for event fields: %s",
					Fstrerror(Ferror)) ;
	}

	/* post the event */
	else if (tppost ("BANK_CTR_OPENACCT",	/* event name */
			 (char *)transf,	/* data */
			 0L,			/* len */
			 TPNOTRAN | TPSIGRSTRT) == -1) {

	    /* If event broker is not reachable, ignore the error.
	     * This would happen if an event broker was not configured.
	     */
	    if (tperrno != TPENOENT)
		(void)sprintf (emsg, "tppost failed: %s", tpstrerror(tperrno));
	}

	/* any error in processing the post event ? */
	
	if (strcmp (emsg, "") != 0) {
	    (void)userlog("WARN: Event BANK_CTR_OPENACCT not posted: %s", emsg);
	    (void)strcpy (emsg, "") ;
	}

	/* delete the event fields from the buffer being returned */
	(void)Fdel (transf, EVENT_NAME, 0) ;
	(void)Fdel (transf, EVENT_TIME, 0) ;
	(void)Fdel (transf, AMOUNT, 0) ;

	tpreturn(TPSUCCESS, 0, transb->data, 0L, 0);
}

/*
 * Service to close an account
 */

void
#if defined(__STDC__) || defined(__cplusplus)
CLOSE_ACCT(TPSVCINFO *transb)
#else
CLOSE_ACCT(transb)
TPSVCINFO *transb;
#endif
{
	FBFR *transf;			/* fielded buffer of decoded message */

	/* set pointer to TPSVCINFO data buffer */
	transf = (FBFR *)transb->data;

	/* must have valid account number */
	if (((account_id = Fvall(transf, ACCOUNT_ID, 0)) < MINACCT) || 
	    (account_id > MAXACCT)) {
		(void)Fchg(transf, STATLIN, 0, "Invalid account number", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        }

	/* Retrieve AMOUNT to be deleted */
	/* EXEC SQL declare ccur cursor for
		select BALANCE from ACCOUNT where ACCOUNT_ID = :account_id; */ 

	/* EXEC SQL open ccur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )151;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&account_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL fetch ccur into :bal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )170;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&bal;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(float);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* nothing found */
		(void)Fchg(transf, STATLIN, 0, getstr("account",SQLCODE), (FLDLEN)0);
		/* EXEC SQL close ccur; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )189;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}
	/* EXEC SQL close ccur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )204;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	/* Do final withdrawal */

	/* make withdraw request buffer */
        if ((reqfb = (FBFR *)tpalloc(FMLTYPE,NULL,transb->len)) == (FBFR *)NULL) {
                (void)userlog("tpalloc failed in close_acct\n");
                (void)Fchg(transf, STATLIN, 0, 
			   "Unable to allocate request buffer", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        }
        reqlen = Fsizeof(reqfb);
        (void)Finit(reqfb,(FLDLEN)reqlen);

	/* put ID in request buffer */
        (void)Fchg(reqfb,ACCOUNT_ID,0,(char *)&account_id, (FLDLEN)0);

	/* put amount into request buffer */
	(void)sprintf(amts,"%.2f",bal);
	(void)Fchg(reqfb,SAMOUNT,0,amts, (FLDLEN)0);

	/* increase the priority of this withdraw */
	if (tpsprio(PRIORITY, 0L) == -1)
		(void)userlog("Unable to increase priority of withdraw");

	/* tpcall to withdraw service to remove remaining balance */
	if (tpcall("WITHDRAWAL", (char *)reqfb, 0L, (char **)&reqfb, 
		   (long *)&reqlen,TPSIGRSTRT) == -1) {
		(void)Fchg(transf, STATLIN, 0,"Cannot make withdrawal", (FLDLEN)0);
		tpfree((char *)reqfb);
		tpreturn(TPFAIL, 0,transb->data, 0L, 0);
	}

	/* Delete account record */

	/* EXEC SQL delete from ACCOUNT where ACCOUNT_ID = :account_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "delete  from ACCOUNT  where ACCOUNT_ID=:b0";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )219;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&account_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* Failure to delete */
		(void)Fchg(transf, STATLIN, 0,"Cannot close account", (FLDLEN)0);
		tpfree((char *)reqfb);
		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}

	/* prepare buffer for successful return */
	(void)Fchg(transf, SBALANCE, 0, Fvals(reqfb,SAMOUNT,0), (FLDLEN)0);
	(void)Fchg(transf, FORMNAM, 0, "CCLOSE", (FLDLEN)0);
	(void)Fchg(transf, STATLIN, 0, " ", (FLDLEN)0);
	tpfree((char *)reqfb);
	tpreturn(TPSUCCESS, 0, transb->data, 0L, 0);
}

/*
 * Service to get the ssn number from an exist account
 */

void
#if defined(__STDC__) || defined(__cplusplus)
ACCT_SSN(TPSVCINFO *transb)
#else
ACCT_SSN(transb)
TPSVCINFO *transb;
#endif
{
	FBFR   *transf;	/* fielded buffer of decoded message */
	FLDLEN len;

	/* set pointer to TPSVCINFO data buffer */

	transf = (FBFR *)transb->data;

	/* must have valid account number */
	if (((account_id = Fvall(transf, ACCOUNT_ID, 0)) < MINACCT) || 
	    (account_id > MAXACCT)) {
		(void)Fchg(transf, STATLIN, 0, "Invalid account number", (FLDLEN)0);
                tpreturn(TPFAIL, 0, transb->data, 0L, 0);
        }

	/* Retrieve the SSN number */
	/* EXEC SQL declare scur cursor for
		select SSN from ACCOUNT where ACCOUNT_ID = :account_id; */ 

	/* EXEC SQL open scur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )238;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&account_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL fetch scur into :ss_n; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )257;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)ss_n;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (SQLCODE != SQL_OK) {		/* nothing found */
		(void)Fchg(transf, STATLIN, 0, getstr("account",SQLCODE), (FLDLEN)0);
		/* EXEC SQL close scur; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )276;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		tpreturn(TPFAIL, 0, transb->data, 0L, 0);
	}
	/* EXEC SQL close scur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )291;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	/* prepare buffer for successful return */
	(void)Fchg(transf, SSN, 0, (char *)&ss_n, (FLDLEN)0);
	tpreturn(TPSUCCESS, 0, transb->data, 0L, 0);
}

