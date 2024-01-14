# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

# Create the tasm user for the TSAM Database

source checkuser.sh
source checkhost01.sh
source checkenv.sh

ssh host02 sqlplus / AS sysdba @$LABHOME/lab17-1/crusers.ora

