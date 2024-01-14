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
echo "*** Setting Necessary Environment Variables ***"
echo ""
. ./setqmconfig.sh

echo ""
echo "*** Creating Queuespace Device; Initializing Queuespace; Defining Queues ***"
echo ""
qmadmin <<!  >/dev/null
crdl ${QMCONFIG} 0 1000
qspacecreate QSPACE 59999 800 3 25 10 100 ErrorQ 'y' 16
qopen QSPACE
qcreate ErrorQ fifo none 2 30 80% 0% ""
qcreate ZIPCODEFINDER fifo none 2 30 80% 0% ""
qcreate ReplyQ fifo none 2 30 80% 0% ""
qclose
quit
!

echo ""
echo "*** . . .COMPLETED. . . ***"
echo ""
