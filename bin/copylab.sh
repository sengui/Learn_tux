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
source checkenv.sh

files=$PWD/labfiles
builddir=$LABHOME/build

if [ ! -f $files ]; then
    echo "$files does not exist, exiting..."
    exit
fi

echo ""

#Read file list from file
for i in `cat $files`
do
    echo "Copying $builddir/$i to $APPDIR"
    cp "$builddir/$i" $APPDIR
done

echo ""

 
