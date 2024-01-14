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

#This script resets practice to its original state
rm -f ubb
rm -f ubb.archive
rm -f access.*
rm -f ULOG*

ssh host02 sqlplus / AS sysdba @$LABHOME/lab17-1/dlusers.ora >/dev/null 2>&1

#Uninstall TSAM to reset practice
$LABHOME/bin/backup/uninstall_tsam.sh






