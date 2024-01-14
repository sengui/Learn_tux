#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

#Determine which host this script is running on
host=`echo $HOSTNAME | sed "s/.example.com//"`

#Perform operations only on host01
if [ "$host" != "host01" ]; then
    echo "This script must be run on host01."
    exit
fi


