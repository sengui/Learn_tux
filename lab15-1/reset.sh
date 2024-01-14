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
rm -f TuxApp.env

rm -f serverResults.out
rm -f clientResults.out
rm -f machineResults.out
rm -f server21.out
rm -f stop21.ud
rm -f addSimpserv.ud
rm -f addResult.out
rm -f updateResponse.out
rm -f ubbBeforeUpdate.tux
rm -f ubbAfterUpdate.tux
rm -f ubbBeforeRollback.tux
rm -f rollbackResponse.out
rm -f ubbAfterRollback.tux

#Recreate getInfo.ud file IMPORTANT: Leave last blank line intact!
cat <<! > getInfo.ud
# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------
# Example GET command
SRVCNM	.TMIB
TA_OPERATION	GET
TA_CLASS	T_SERVER

!









