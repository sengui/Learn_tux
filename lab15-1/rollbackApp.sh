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
echo "*** Executing rollbackApp script ***"
echo ""
tmunloadcf > ubbBeforeRollback.tux
ud32 -C tpsysadm < rollbackApp.ud > rollbackResponse.out
tmunloadcf > ubbAfterRollback.tux

echo ""
echo "*** Deleting Servers from APPDIR ***"
echo ""
rm $APPDIR/PingServer
rm $APPDIR/BigUpdate
rm $APPDIR/BigUpdate.out

echo ""
echo "*** Rollback Complete!                                          ***"
echo "*** UBB archives have been created                              ***"
echo "*** You should also check tmadmin and the APPDIR to validate... ***"
echo ""
