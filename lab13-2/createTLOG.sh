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
source checkhost01.sh
source checkenv.sh

echo ""
echo "*** Creating TLOG Device; Initializing TLOG ***"
echo ""
tmadmin <<!  >/dev/null
crdl -b 200 -z ${APPDIR}/TLOGDEVICE
crlog -m SITE1
quit
!

echo ""
echo "*** . . .COMPLETED. . . ***"
echo ""
