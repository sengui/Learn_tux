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

#This script sets up the practice, Must call cleanup.sh on host01 because it checks for this.
ssh host01 cleanup.sh
./reset.sh

#Build bankapp. Clients go to lab dir and servers go to $APPDIR
cd source
make -f bankapp.mk
cd -
./crbank.sh


