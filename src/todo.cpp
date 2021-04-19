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

//NECESSITIES
void init()
{
	FILE* file;
	if(file = fopen(PATH,"a"))
		fclose(file);
	printf("\nTODO repository created!\n\n");
}
bool fileExists()
{
	FILE* file;
	if(file=fopen(PATH,"r"))
	{
		fclose(file);
		return true;
	}
	else return false;
}
bool emptyFile()
{
	FILE* file;
	file=fopen(PATH,"rb");
	fseek(file,0L,SEEK_END);
	if(ftell(file)==0)
	{
		fclose(file);
		return true;
	}
	else
	{
		fclose(file);
		return false;
	}
}
void showAll()
{
	char buffer[100];
	if(!emptyFile())
	{
		strcpy(buffer,"cat -n");
		strcat(buffer,PATH);
		system(buffer);
	}
	else
		printf("\nNo todos on the list\nTry use - todo add \"todo name\"\n\n");
}
void showCompleted()
{
	char buffer[100];
	strcpy(buffer,"cat -n");
	strcat(buffer,PATH);
	strcat(buffer," | awk '/[0-9]\\t\\-/'");
	system(buffer);
}
void showTodos()
{
	char buffer[100];
	strcpy(buffer, "cat -n ");
    strcat(buffer, PATH);
    strcat(buffer, " | awk '/[0-9]\\t\\+/'");
    system(buffer);
}
void addTodo(char todo[])
{
	char buffer[400];
	strcpy(buffer, "echo \"+ ");
	strcat(buffer, todo);
	strcat(buffer, "\" > ");
	strcat(buffer, TEMP);
	strcat(buffer, "; cat ");
	strcat(buffer, PATH);
	strcat(buffer, " >> ");
	strcat(buffer, TEMP);
	strcat(buffer, "; cat ");
	strcat(buffer, TEMP);
	strcat(buffer, " > ");
	strcat(buffer, PATH);
	system(buffer);
}
void completeTodo(char todo[])
{
	char buffer[200];
	strcpy(buffer, "sed -n ");
	strcat(buffer, todo);
	strcat(buffer, "p ");
	strcat(buffer, PATH);
	strcat(buffer, " | sed 's/^\\+/\\-/' >> ");
	strcat(buffer, PATH);
	strcat(buffer, "; sed ");
	strcat(buffer, todo);
	strcat(buffer, "d ");
	strcat(buffer, PATH);
	strcat(buffer, " > ");
	strcat(buffer, TEMP);
	strcat(buffer, "; cat ");
	strcat(buffer, TEMP);
	strcat(buffer, " > ");
	strcat(buffer, PATH);
	system(buffer);
}
void deleteTodo(char todo[])
{
	char buffer[200];
	strcpy(buffer, "sed -e ");
	strcat(buffer, todo);
	strcat(buffer, "d ");
	strcat(buffer, PATH);
	strcat(buffer, " > ");
	strcat(buffer, TEMP);
	strcat(buffer, "; cat ");
	strcat(buffer, TEMP);
	strcat(buffer, " > ");
	strcat(buffer, PATH);
	system(buffer);
}
void deleteTodos()
{
	char buffer[50];
	strcpy(buffer, "> ");
	strcat(buffer, PATH);
	system(buffer);
}
void showHelp()
{
	printf("\n TODO - command line todo list MM (c) 2012\n");
	printf(" --------------------------------------------\n\n");
	printf(" Usage:\ttodo [option] <string>\n");
	printf("\n List of options\n\n");
	printf(" init\tstarts todo list on current folder\n");
	printf(" +\tdisplays only active todos\n");
	printf(" -\tdisplay only completed todos\n");
	printf(" add\tfollowed by QUOTED string (ex.:\"my new todo\") includes a new todo\n");
	printf(" done\tfollowed by todo's ID number, marks todo as completed\n");
	printf(" del\tfollowed by todo's ID number, remove todo from current list\n");
	printf(" clean\tdeletes all list of todos ***USE WITH MODERATION***\n");
	printf(" uninstall\tremove TODO application\n");
	printf(" help\tdisplay a quick command reference for the system\n\n");
}
void uninstallTodo()
{
	system("/usr/local/todo/./uninstall.sh");
}