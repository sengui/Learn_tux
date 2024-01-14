#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

# This script is designed to be run from the solution directory

source checkuser.sh
source checkhost01.sh
source checkenv.sh

echo ""
echo "*** Building Application Server Executables ***"
echo ""
buildserver -v -o $APPDIR/InqServer -s INQ:Inq -f ../Inq.c
buildserver -v -o $APPDIR/DeleteServer -s DELETE:Delete -f ../Delete.c
buildserver -v -o $APPDIR/UpdateServer -s UPDATE:Update -f ../Update.c

echo *** Building Client Executable ***
echo ""
buildclient -v -o ../clientdb -f ../clientdb.c

echo ""
echo "*** LAB SETUP IS COMPLETE ***"
echo ""


 
