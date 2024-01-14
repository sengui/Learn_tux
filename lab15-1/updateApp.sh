#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

# This script should only be executed from the Lab15 directory

source checkuser.sh
source checkenv.sh

echo ""
echo "*** Copying Servers to APPDIR ***"
echo ""
cp $LABHOME/build/PingServer $APPDIR
cp $LABHOME/build/BigUpdate $APPDIR

echo ""
echo "*** Executing updateApp.ud script ***"
echo ""
tmunloadcf > ubbBeforeUpdate.tux
ud32 -C tpsysadm < updateApp.ud > updateResponse.out
tmunloadcf > ubbAfterUpdate.tux

echo ""
echo "*** Update Complete!                             ***"
echo "*** UBB archives have been created               ***"
echo "*** You should also check tmadmin to validate... ***"
echo ""
