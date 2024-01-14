#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------     

source checkuser.sh
source checkenv.sh

save=$PWD
dest=$LABHOME/build

cd $LABHOME/source

echo ""
echo "*** Building Application Server Executables ***"
echo ""
buildserver -o $dest/DBServer -s INQ:Inq -s DELETE:Delete -s UPDATE:Update -f "Inq.c Delete.c Update.c"
buildserver -o $dest/simpserv -s TOUPPER -f simpserv.c
buildserver -o $dest/serverA -s SVCA -f serverA.c
buildserver -o $dest/serverB -s SVCB -f serverB.c
buildserver -o $dest/serverC -s SVCC -f serverC.c
buildserver -o $dest/BigUpdate -s PROBLEM,UPDATE2:BigUpdate -f BigUpdate.c
buildserver -o $dest/ClientMonitor -s WATCHDOG -f ClientMonitor.c
buildserver -o $dest/SecurityTest -s GETAPPKEY -f serversec.c
buildserver -o $dest/PingServer -s SVC_PING:PING -f serverping.c
buildserver -o $dest/DDRServer -s DEPOSIT,WITHDRAW -f serverddr.c
buildserver -o $dest/ZipServer -s ZIPCODEFINDER -f serverzip.c

echo ""
echo "*** Building Native Client Executables ***"
echo ""
buildclient -o $dest/clientdb -f clientdb.c
buildclient -o $dest/clientdba -f clientdba.c
buildclient -o $dest/simpcl -f simpcl.c
buildclient -o $dest/clientsecure -f clientsec.c -l /usr/lib64/libncurses.so
buildclient -o $dest/clientping -f clientping.c
buildclient -o $dest/clientddr -f clientddr.c
buildclient -o $dest/clientenq -f clientenqueue.c
buildclient -o $dest/clientdeq -f clientdequeue.c

echo ""
echo "*** Building Workstation Client Executables ***"
echo ""
buildclient -o $dest/wscdba -f clientdba.c -w
buildclient -o $dest/wscdb -f clientdb.c -w
buildclient -o $dest/wscsecure -f clientsec.c -l /usr/lib64/libncurses.so -w
buildclient -o $dest/wscsimpcl -f simpcl.c -w
buildclient -o $dest/wscping -f clientping.c -w
buildclient -o $dest/wscddr -f clientddr.c -w
buildclient -o $dest/wscenq -f clientenqueue.c -w
buildclient -o $dest/wscdeq -f clientdequeue.c -w

echo ""
echo "*** LAB SETUP IS COMPLETE ***"
echo ""

cd $save
 
