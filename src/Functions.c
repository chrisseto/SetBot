#include "../headers/Functions.h"
Command COMMANDS[] = {
	{"say",&say,"Says [args]"},
	{"quit",&quit, "Quits"},
	{"list",&list, "List Commands"},
	{"roll",&roll, "Roll a dice with [args] sides"}
};
short COMMAND_LENGTH = 3; //ALWAYS CHANGE TO REFLECT ABOVE ^ //Maybe be made dynamic later on
//Make buffers with malloc and free <-TODO
void say(char *message)
{
	char buff[strlen(message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+1];
	sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,message);
	printf("%s: %s\n",NickName,message);
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
	char *buff = malloc(strlen(arg)+5);
	sprintf(buff,"PONG %s\r\n",arg+1);
	printf("%s",buff);
	sendToServer(buff);
	free(buff);
}
void list(char * ness)
{
	char *buff=malloc(255);
	int len = 0;
	for(int i = 0; i < 4; i++)
	{
		sprintf(buff,"%s: %s\r\n",COMMANDS[i].text,COMMANDS[i].description);
		say(buff);
		memset(buff,0,sizeof(buff));
	}
	free(buff);
}
void rpn(char* args)
{
	//There will be another c file for this let me tell you....
}
void roll(char* arg)
{
	srand(time(NULL)); //PLANT THE SEEDS
	int num = rand() % atoi(arg); //Also Should work
	char *buff = malloc(255);
	sprintf(buff,"You Rolled %d",num);
	say(buff);
	free(buff);
} 

