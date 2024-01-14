#!/bin/bash

# ------------------------------------------------------------------------
# -- DISCLAIMER:
# --    This script is provided for educational purposes only. It is NOT
# --    supported by Oracle World Wide Technical Support.
# --    The script has been tested and appears to work as intended.
# --    You should always run new scripts on a test instance initially.
# -- 
# ------------------------------------------------------------------------

source /practices/tux/bin/checkuser.sh

#Automatically set env for proper course
if [ -z "`grep /practices/tux /home/oracle/.bashrc`" ]; then
    #Delete setenv.sh line from bashrc in case another course is setup
    sed -i '/setenv.sh/ d' /home/oracle/.bashrc 2>/dev/null
    echo ". /practices/tux/bin/setenv.sh" >> $HOME/.bashrc
fi

#Course variables
export LABHOME=/practices/tux
export LABBIN=$LABHOME/bin
export INSTALLDIR=/install
export APP=/u01/app

#Database variables
export ORACLE_BASE=$APP/db11g
export ORACLE_HOME=$ORACLE_BASE/product/11.2.0/dbhome_1
export ORACLE_SID=orcl

#Product variables
export JAVA_HOME=$APP/jdk
export TUXDIR=/opt/tuxedo
export TSAMDIR=/u01/app/fmwgrid/tsam
export DOMAINS=/u01/domains
export APPDIR=$DOMAINS/tuxapps
export TUXCONFIG=$APPDIR/tuxconfig
export SALTCONFIG=$APPDIR/saltconfig
export MW_HOME=$APP/fmw
export WL_HOME=$MW_HOME/wlserver
export NLSPATH=$TUXDIR/locale
export LANG=C

#Keeps PATH settings idempotent
if [ -z `echo $PATH | grep $TUXDIR` ]; then
    export PATH=$TUXDIR/bin:$PATH
fi
if [ -z `echo $PATH | grep $JAVA_HOME` ]; then
    export PATH=$JAVA_HOME/bin:$PATH
fi
if [ -z `echo $PATH | grep ":/sbin"` ]; then
    export PATH="/sbin":$PATH
fi
if [ -z `echo $PATH | grep "db11g"` ]; then
    export PATH=$ORACLE_HOME/bin:$PATH
fi
if [ -z "`echo $PATH | grep /u01/app/fmw/oracle_common/modules`" ]; then
    export PATH=$PATH:$MW_HOME/oracle_common/modules/org.apache.ant_1.7.1/bin
fi
if [ -z `echo $PATH | grep "jxplorer-3.2"` ]; then
    export PATH=.:$APP/jxplorer-3.2:$PATH
fi
if [ -z `echo $PATH | grep "python"` ]; then
    export PATH="/usr/lib64/python2.6/site-packages/orca/scripts/apps":$PATH
fi
#This removes the labs bin from PATH and puts it back in at the beginning just in case
export PATH=`echo $PATH | sed "s=$LABBIN:=="`
export PATH="$LABBIN":$PATH

#Keep LD_LIBRARY_PATH settings idempotent
if [ -z `echo $LD_LIBRARY_PATH | grep $TUXDIR` ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$TUXDIR/lib
fi
if [ -z `echo $LD_LIBRARY_PATH | grep $ORACLE_HOME` ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ORACLE_HOME/lib
fi
if [ -z `echo $LD_LIBRARY_PATH | grep $JAVA_HOME` ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$JAVA_HOME/jre/lib/amd64/server
fi
if [ -z `echo $LD_LIBRARY_PATH | grep /usr/lib` ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib
fi

#Keep CLASSPATH settings idempotent
if [ -z `echo $CLASSPATH | grep "weblogic.jar"` ]; then
    . "${WL_HOME}/server/bin/setWLSEnv.sh" >/dev/null
fi
if [ -z `echo $CLASSPATH | grep "jxplorer.jar"` ]; then
    export CLASSPATH=$CLASSPATH:/u01/app/jxplorer-3.2/jars/jxplorer.jar
fi

#Convenience aliases
alias cls='clear'
alias l.='ls -d .* --color=tty'
alias ll='ls -l --color=tty'
alias ls='ls --color=tty'
alias g="gedit"
alias which='alias | /usr/bin/which --tty-only --read-alias --show-dot --show-tilde'
alias bin='cd $LABBIN'
alias labs='cd $LABHOME'
alias install='cd $INSTALLDIR'
alias src='cd $LABHOME/source'
alias docs='cd $LABHOME/docs'
alias build='cd $LABHOME/build'
alias domains='cd $DOMAINS'
alias app='ll $APPDIR'
alias appdir='cd $APPDIR'
alias wls='cd $DOMAINS/wlsadmin'
alias fmw='cd /u01/app/fmw'
alias grid='cd /u01/app/fmwgrid'
alias tux='cd $TUXDIR'
alias tsam='cd $TSAMDIR'
alias 33='cd $LABHOME/lab03-3'
alias 51='cd $LABHOME/lab05-1'
alias 52='cd $LABHOME/lab05-2'
alias 61='cd $LABHOME/lab06-1'
alias 71='cd $LABHOME/lab07-1'
alias 81='cd $LABHOME/lab08-1'
alias 82='cd $LABHOME/lab08-2'
alias 91='cd $LABHOME/lab09-1'
alias 101='cd $LABHOME/lab10-1'
alias 111='cd $LABHOME/lab11-1'
alias 112='cd $LABHOME/lab11-2'
alias 121='cd $LABHOME/lab12-1'
alias 131='cd $LABHOME/lab13-1'
alias 132='cd $LABHOME/lab13-2'
alias 141='cd $LABHOME/lab14-1'
alias 151='cd $LABHOME/lab15-1'
alias 161='cd $LABHOME/lab16-1'
alias 171='cd $LABHOME/lab17-1'
alias 181='cd $LABHOME/lab18-1'

alias tma='tmadmin'
alias tmb='tmboot -y'
alias tms='tmshutdown -y'
alias tml='tmloadcf -y ubb'
alias psr='echo psr | tmadmin'
alias psc='echo psc | tmadmin'
alias pclt='echo pclt | tmadmin'
alias pq='echo pq | tmadmin'
alias pt='echo pt | tmadmin'

export PS1='$PWD>'

