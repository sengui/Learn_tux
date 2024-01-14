#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

#Set the environment if it isn't set by default; otherwise, just go with the current environment
if [ -z `echo $TUXDIR` ]; then
    . /practices/tux/bin/setenv.sh
fi


