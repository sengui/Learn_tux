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

#Setting the QMCONFIG Environment Variable ***"
export QMCONFIG=$APPDIR/QSDEVICE

export FLDTBLDIR=${TUXDIR}/udataobj
export FIELDTBLS=Usysflds,tpadm
export FLDTBLDIR32=${TUXDIR}/udataobj
export FIELDTBLS32=Usysfl32,tpadm,evt_mib

