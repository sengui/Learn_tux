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

#Have to set ORACLE_HOME and TUXDIR here for the rolling patch uninstaller
#This is not kept for the calling shell
export ORACLE_HOME=/u01/app/fmwgrid
export TUXDIR=$ORACLE_HOME/tuxedo

#Uninstall Tuxedo Patch
if [ -d "$TUXDIR/uninstaller_RP024" ]; then
    cd $TUXDIR/uninstaller_RP024
    ./uninstall -i silent
    cd -
fi

#Uninstall Tuxedo
if [ -d "$TUXDIR/uninstaller" ]; then
    cd $TUXDIR/uninstaller
    ./Uninstall_Tuxedo_12.1.1.0 -i silent
    cd -
fi
if [ -d "$TUXDIR" ]; then
    rm -rf $TUXDIR
fi

