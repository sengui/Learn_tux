#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

labs=/practices/tux

source $labs/bin/checkuser.sh
source $labs/bin/checkhost01.sh
source $labs/bin/checkenv.sh

#Which host(s) need tmshutdown? Host01 is the default
reset="host01"

#Use tmunloadcf to determine which host contains a valid tuxconfig file
#so we can call tmshutdown on that host. If tmunloadcf fails, it just means
#that there is no tuxconfig present, in which case a tmshutdown would be moot.

#Lab 12 must do tmshutdown on host02 only
if [ ! -z `ssh host02 "tmunloadcf 2>/dev/null| grep 12-1 | grep ULOG"` ]; then
    reset="host02"
fi
#Lab 14 must do tmshutdown on both hosts
if [ ! -z `tmunloadcf 2>/dev/null | grep 14-1` ]; then
    reset="both"
fi

find /install -name "ULOG.*" | xargs rm -f
rm -f /u01/ULOG*; rm -f /u01/domains/ULOG*; rm -f /home/oracle/ULOG*; rm -f /home/oracle/Tuxedo*.log
ssh host02 "rm -f /u01/domains/ULOG*; rm -f /home/oracle/ULOG*; rm -f /home/oracle/Tuxedo*.log"

#Go through all of tux practice folders (except for docs) and delete all ULOG*, access.*, and other files
#This is because Tuxedo sometimes doesn't have a setting and just creates a ULOG or other file in the current folder
dirlist=`ls -1 $LABHOME | grep -v docs`
for dir in $dirlist; do
    find $LABHOME/$dir -name "*ULOG*" -o -name "access.*" | xargs rm -f
done

echo -e "\nResetting Tuxedo environment on host01"
resetAppdir.sh $reset
echo -e "\nResetting Tuxedo environment on host02"
ssh host02 /practices/tux/bin/resetAppdir.sh $reset

echo ""
echo "*** LAB CLEANUP IS COMPLETE ***"
echo ""
cd $save

