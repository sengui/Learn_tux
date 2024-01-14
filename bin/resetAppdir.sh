#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

labs=/practices/tux

source $labs/bin/checkuser.sh
source $labs/bin/checkenv.sh

#Determine which host this script is running on
host=`echo $HOSTNAME | sed "s/.example.com//"`

#Parse args
reset=$1

if [ -z $reset ]; then
    reset="host01"
fi

save=$PWD
cd $DOMAINS

#echo "Host=$host :: reset=$reset"

#Perform certain operations only on host01
if [ "$host" == "host01" ]; then
    if [ ! -z `echo $reset | egrep "host01|both"` ]; then
        #Call tmshutdown to make sure Tuxedo is not running
        echo "Calling tmshutdown on host01"
        tmshutdown -y 2>/dev/null
    fi

    #Remove any /Q IPC resources
    cd $LABHOME/lab13-1
    ./cleanIPC.sh 2>/dev/null
    rm -f ULOG*

    #Remove any /Q IPC resources
    cd $LABHOME/lab13-2
    ./cleanIPC.sh 2>/dev/null
    rm -f ULOG*
fi

#Perform certain operations only on host01
if [ "$host" == "host02" ]; then
    if [ ! -z `echo $reset | egrep "host02|both"` ]; then
        #Call tmshutdown to make sure Tuxedo is not running
        echo "Calling tmshutdown on host02"
        tmshutdown -y 2>/dev/null
    fi
fi

#Remove IPC resources only if a tuxconfig file exists because it doesn't work otherwise
if [ -f "$TUXCONFIG" ]; then
    echo ""
    echo "*** Checking to see if all IPC resources were removed ***"
    echo ""
    tmipcrm -y 2>/dev/null
fi

#If DOMAINS is not set, this potentially deletes entire home folder
if [ ! -z `echo $DOMAINS` ]; then
    cd $DOMAINS/tuxapps

    #Remove all APPDIR files
    rm -rf * 2>/dev/null
    rm -rf .* 2>/dev/null
else
    echo "There was a problem because DOMAINS was not set properly"
fi

cd $save
