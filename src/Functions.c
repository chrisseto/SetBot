#include "../headers/Functions.h"
Command COMMANDS[] = {
	{"say",&say,"say [args]. Says [args]"},
	{"pong",&pong, "Pongs Server Don't Call"},
	{"quit",&quit, "Quits"},
	{"list",&list, "List Commands"}
};

void say(char *message)
{
	char buff[256];
	sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,message);
	printf("saying %s\n",buff);
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
	for(int i = 0; i < sizeof(COMMANDS)/sizeof(COMMANDS[0]); i++)
	{
		sprintf(buff,"%d. %s: %s\n",i,COMMANDS[i].text,COMMANDS[i].description);
	}
	sprintf(buff,"\r\n");
	say(buff);
}
