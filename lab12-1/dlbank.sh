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

#We pipe output to nowhere because when the users do not exist, the errors are ugly
#and could be confusing to students. When the users do exist, then they just get deleted
#so no message is really needed.
sqlplus / AS sysdba @dlusers.ora >/dev/null



