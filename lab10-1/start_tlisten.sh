# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

#Starts the tlisten process on both machines

source checkuser.sh
source checkhost01.sh
source checkenv.sh

#Starts host01
tlisten -l //host01:3050

#Starts host02
ssh host02 tlisten -l //host02:3050
