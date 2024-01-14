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
tmqadmin <<!  >/dev/null
crdl ${QMCONFIG} 0 50000
qspacecreate -n 4096B -Q 20 -T 301
QSPACE
54320
2048
15
100
100
100
ErrorQ
y
16
y
y
y
qopen QSPACE
qcreate -t PQ
ErrorQ
fifo
none
2
30
80%
0%

qcreate -t PQ -a y
ZIPCODEFINDER
fifo
none
2
30
80%
0%

quit
!

echo ""
echo "*** . . .COMPLETED. . . ***"
echo ""
