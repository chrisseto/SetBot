#include "../headers/Functions.h"
Command COMMANDS[] = {
	(Command){.text = "say", .func = &say}
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
