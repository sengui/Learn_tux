#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# --
# ------------------------------------------------------------------------


#This script resets practice files to its original state
rm -f ubb
rm -f ubb.archive
rm -f access.*
rm -f ULOG*

rm -f source/*.o
rm -f audit
rm -f auditcon
rm -f bankclt
rm -f bankmgr
rm -f gentran
rm -f gendata
rm -f pop.out

#Remove database users, cascading which deletes all their tables as well
dlbank.sh



