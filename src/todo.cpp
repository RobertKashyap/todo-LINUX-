/*
	TODO - a calibrated todo list accessible from terminal
	C++ based, configured to linux directory structures
*/

//LIBRARIES USED
#include "cstdio"
#include "cstring"

//CONSTANTS
#define PATH "./.todo_file"
#define TEMP "./.todo_tmp"

//FUNCTIONS
void init();
bool fileExists();
bool emptyFile();
void showAll();
void showCompleted();
void showTodos();
void addTodo(char todo[]);
void completeTodo(char todo[]);
void deleteTodo(char todo[]);
void deleteTodos();
void showHelp();
void uninstallTodo();

//MAIN PLOT
int main(int argc, char const *argv[])
{
	bool exists=fileExists();
	//for terminal arguments on the terminal command
	if (argv[1]&&exists)
	{
		//if argument is "-" show only completed todos
		if(strcmp(argv[1],"-")==0)
			showCompleted();

		//if argument is "+" show only active todos
		else if(strcmp(argv[1],"+")==0)
			showTodos();
		
		//if argument is "add" and next argument exists,include new todo
		else if(strcmp(argv[1],"add")==0&&argv[2])
			addTodo(argv[2]);

		//if argument is "done" and next argument exists,move todo to completed list
		else if(strcmp(argv[1],"done")==0&&argv[2])
			completeTodos();

		//if argument is "del" and next argument exists, delete corresponfing todo
		else if(strcmp(argv[1],"del")==0&&argv[2])
			deleteTodo(argv[2]);

		//if argument is "clean",remove all todos
		else if(strcmp(argv[1],"clean")==0)
			deleteTodos();

		//if argument is "help",display commands
		else if(strcmp(argv[1],"help")==0)
			showHelp();

		//if argument is "uninstall" sadly :(
		else if(strcmp(argv[1],"uninstall")==0)
			uninstallTodo();
		else showAll();
	}
		
	else if(exists)
		showAll();

	//if argument is "init",initialize the todo list
	else if(argv[1]&&strcmp(argv[1],"init")==0)
		init();
	
	else
		printf("\nTODO repository does not exists!! Try use - todo init\n\n");
}//main ends