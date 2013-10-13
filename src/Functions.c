#include "../headers/Functions.h"
Command COMMANDS[] = {
	{"say",&say,"Says [args]"},
	{"quit",&quit, "Quits"},
	{"list",&list, "List Commands"}
};
short COMMAND_LENGTH = 3; //ALWAYS CHANGE TO REFLECT ABOVE ^ //Maybe be made dynamic later on
void say(char *message)
{
	char buff[strlen(message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+1];
	sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,message);
	printf("saying %s",buff);
	sendToServer(buff);
}
void quit(char *ness)
{
	printf("%s :Leaving\n",COMMAND_STRINGS[7]);
	char buff[255];
	sprintf(buff,"%s :Leaving\r\n",COMMAND_STRINGS[7]);
	sendToServer(buff);
	CONNECTED=0;
	QUIT=1;
}
void pong(char *arg)
{
	char buff[strlen(arg)+5];
	sprintf(buff,"PONG %s",arg);
	say(buff);
}
void list(char * ness)
{
	char buff[255];
	int len = 0;
	for(int i = 0; i < 4; i++)
	{
		sprintf(buff,"%s: %s\r\n",COMMANDS[i].text,COMMANDS[i].description);
		say(buff);
		memset(buff,0,sizeof(buff));
	}
}
