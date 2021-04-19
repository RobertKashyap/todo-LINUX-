#!/bin/bash
#INSTALLATION MESSAGE
echo ""
echo "TODO initiating installation..."

#CHECK IF USER HAS ROOT PERMISSION
if [[ $EUID -ne 0 ]]; then
   echo ""
   echo "ERROR"
   echo "say I AM ROOT"
   echo "try this: -> sudo ./install.sh"
   echo ""
   exit 1
fi

#CREATING DIRECTORY
mkdir /usr/local/todo

#MOVE UNINSTALL SCRIPT
cp uninstall.sh /usr/local/todo

#COMPILING PROGRAM
g++ todo.cpp -o todo; mv todo /usr/bin/

echo "...done. Thank you for using TODO!!!"
echo ""
