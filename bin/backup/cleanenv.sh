

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
source $labs/bin/checkhost01.sh
source $labs/bin/checkenv.sh

#Shuts Tuxedo, cleans IPC, and clears APPDIR on both hosts
#Also deletes any random ULOG* and access.* files
cleanup.sh

#Call reset.sh in all practices
dirlist=`find $labs/lab* -name "reset.sh" | sed "s=/reset.sh=="`
for dir in $dirlist; do
    #echo "running resets in $dir"
    if [ -z `echo $dir | grep 12-1` ]; then
        cd $dir; ./reset.sh; cd - >/dev/null
    else
        ssh host02 "cd $dir; ./reset.sh"
    fi
done

#Delete setenv.sh line from bashrc host01
sed -i '/setenv.sh/ d' /home/oracle/.bashrc

#Delete setenv.sh line from bashrc host02
ssh host02 "sed -i '/setenv.sh/ d' /home/oracle/.bashrc"

#Remove products that students install
$labs/bin/backup/uninstall_salt.sh
$labs/bin/backup/uninstall_tmq.sh
$labs/bin/backup/uninstall_tsam.sh
#Purposely do not call the one that uninstalls Tuxedo because it is pre-installed for certain courses
#Students uninstall it themselves for Tuxedo Application Admin course

#Global cleanup requirements
rm -f $labs/build/access.*
rm -f $labs/bin/WSClient.env
rm -f $labs/bin/wscULOG*
rm -f /home/oracle/Tuxedo*
rm -f /home/oracle/SALT*
rm -f /home/oracle/OTMQ*
rm -f /home/oracle/TSAM*



