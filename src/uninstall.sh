#!/bin/bash
#INSTALLATION MESSAGE
echo ""
echo "REMOVING TODO installation..."

#CHECK IF USER HAS ROOT PERMISSION
if [[ $EUID -ne 0 ]]; then
   echo ""
   echo "ERROR"
   echo "say I AM ROOT"
   echo "try this: -> sudo ./uninstall.sh"
   echo ""
   exit 1
fi

#CREATING DIRECTORY
rm -r /usr/local/todo /usr/bin/todo

echo "...done. Feels sorry to lose u."
echo ""
