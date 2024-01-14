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

#This sets libs up that are not set up already
cd $TUXDIR/lib

if [ ! -f libtxml.so.25 ]; then ln -s libtxml.so.25.0 libtxml.so.25; fi
if [ ! -f libticuuc.so.36 ]; then chmod +x libticuuc.so.36.0; ln -s libticuuc.so.36.0 libticuuc.so.36; fi
if [ ! -f libticudata.so.36 ]; then ln -s libticudata.so.36.0 libticudata.so.36; fi


