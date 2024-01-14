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

# This script sets the domain's BDMCONFIG variable
echo ""
echo "*** Setting the BDMCONFIG Environment Variable ***"
echo ""
export BDMCONFIG=$APPDIR/bdmconfig


