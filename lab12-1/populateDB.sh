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
source checkhost02.sh
source checkenv.sh

echo ""
echo "*** Populating the Bank Databases ***"
echo ""
gendata | ud32 -t 30 2>&1 | tee pop.out
