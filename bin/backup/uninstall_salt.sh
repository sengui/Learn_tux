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

tuxdir=/u01/app/fmwgrid/tuxedo

if [ -d "$tuxdir/uninstall_salt" ]; then
    cd $tuxdir/uninstall_salt
    ./Uninstall_SALT_12.1.1.0_for_Tuxedo_12.1.1.0 -i silent
    cd -
fi




