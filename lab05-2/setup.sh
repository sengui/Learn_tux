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

jardir=$TUXDIR/udataobj/tuxj

export LD_LIBRARY_PAH=$LD_LIBRARY_PATH:/u01/app/fmwgrid/tuxedo/lib
echo "te: $LD_LIBRARY_PAH"

#Set up environment required to compile and run Tuxedo Java Servers
if [ -z `echo $CLASSPATH | grep $jardir` ]; then
    export CLASSPATH=$CLASSPATH:$jardir/com.bea.core.jatmi_2.0.0.0.jar:$jardir/com.oracle.tuxedo.tjatmi_12.1.1.0.jar
fi


