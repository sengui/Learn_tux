/*
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 * "/Q Configuration Lab"
 * serverzip.c
 * "Version 1.1"
*/

#include <stdio.h>
#include <string.h>
#include "fml32.h"
#include "atmi.h"
#include "userlog.h"
#include "recordfml.h"

#define MXSTR   80      /* Maximum string length   */

static char *ziplookup[10][2]={{"Liberty Corners","07938"},{"Boston","02101"},{"San Jose","95131"},{"Orlando","32801"},{"Chicago","60601"},{"Dallas","75201"},{"Atlanta","30301"},{"Washington","20001"},{"New York City","10012"},{"Denver","80201"}};

void
#if defined(__STDC__) || defined(__cplusplus)
ZIPCODEFINDER(TPSVCINFO *msg)
#else
ZIPCODEFINDER(msg)
     TPSVCINFO *msg;
#endif
{
  FBFR32 *f;
  char city[MXSTR], zipcode[MXSTR];
  FLDLEN32 len2;
  int i;

  f = (FBFR32 *)msg->data;

  len2 = sizeof(city);
  if (Fget32(f, CITY, 0, city, &len2) == -1) {
    (void)userlog("Postoffice failed to get CITY field -- %s\n",
		  Fstrerror32(Ferror32));
    tpreturn(TPFAIL, 0, (char *)f, 0L, 0);
  }

  for (i = 0; i < 10; i++) {
     if (!strcmp(ziplookup[i][0], city)) {
	(void)strcpy(zipcode, ziplookup[i][1]);
        if (Fchg32(f, ZIPCODE, 0, zipcode, 0) == -1) {
          (void)userlog("Postoffice failed to add ZIPCODE field -- %s\n",
		  Fstrerror32(Ferror32));
          tpreturn(TPFAIL, 0, (char *)f, 0L, 0L);
        }
        tpreturn(TPSUCCESS, 0, (char *)f, 0L, 0L);
     }
  }

  (void)userlog("Postoffice reports city %s not found.\n", city);
  tpreturn(TPFAIL, 0, (char *)f, 0L, 0L);
}
