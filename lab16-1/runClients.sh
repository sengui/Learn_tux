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

echo ""
echo "*** Starting 6 clientdba applications ***"
echo ""
rundir=$LABHOME/build
$rundir/clientdba -v -w1 -i50 -sDELETE &
$rundir/clientdba -v -w1 -i50 -sUPDATE &
$rundir/clientdba -v -w1 -i50 -sINQ &
$rundir/clientdba -v -w1 -i50 -sDELETE &
$rundir/clientdba -v -w1 -i50 -sUPDATE &
$rundir/clientdba -v -w1 -i50 -sINQ &

