
 TODO - command line todo list
===========================================
##Installation
You may need to give execution permission for the installation script, type this:

	chmod +x install.sh

Execute the installation script typing the following command:
        
	sudo ./install.sh

That is it, you are ready to go ;)

##Usage
TODO is projected to work on your local directories. When you run **todo** in your current directory a **".todo_file"** will be created where all your todos will be saved.
    
    todo [option] "string"
    or
    todo [option] 'string,
    or
    todo [option] string ;for single word strings only

##List of options

	+          displays only active todos
	-          display only completed todos
	add        followed by QUOTED string (ex.:"my new todo") includes a new todo
	done       followed by todo's ID number, marks todo as completed
	del        followed by todo's ID number, remove todo from current list
	clean      deletes all list of todos ***USE WITH MODERATION***
	uninstall  remove TODO application
	help       display a quick command reference for the system

##Dependencies
All tools used to build __todo__ can be found in most of the X (linux/unix) distributions, but just to let you know, I am using:

	g++        C++ programing language compiler
	sed        powerful string pre-processor 
	awk        another powerful pre-processor