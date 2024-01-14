# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

# Create Oracle Tables for a bankapp Database

source checkuser.sh
source checkhost02.sh
source checkenv.sh

sqlplus / AS sysdba @crusers.ora
sqlplus tuxbank1/tuxbank1 @crbanktab.ora
sqlplus tuxbank2/tuxbank2 @crbanktab.ora
sqlplus tuxbank3/tuxbank3 @crbanktab.ora


