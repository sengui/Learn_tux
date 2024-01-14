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

#Set QMCONFIG QDEVICE
. ./setqmconfig.sh

#Only try to remove IPC resources if the QDEVICE actually exists otherwise this script causes trouble
if [ -f "$APPDIR/QSDEVICE" ]; then
tmqadmin <<!  >/dev/null
ipcrm -y QSPACE
quit
!
    #Just in case run our own IPC removal script
    ./ipcrmall.sh

    echo ""
    echo "*** . . ./Q IPC RESOURCES REMOVED. . . ***"
    echo ""
fi



