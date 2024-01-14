#

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

tsamhome=/u01/app/fmwgrid/tsam

#Uninstall TSAM patch
if [ -d "$tsamhome/uninstall_tsam12cRP" ]; then
    cd $tsamhome/uninstall_tsam12cRP
    ./uninstall_tsam12cRP -i silent
    cd -
fi

#Uninstall TSAM
if [ -d "$tsamhome/uninstall" ]; then
    cd $tsamhome/uninstall
    ./uninstall -i silent
    cd -
fi
if [ -d "$tsamhome" ]; then
    rm -rf $tsamhome
fi

