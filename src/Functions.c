#include "../headers/Functions.h"

Command COMMANDS[] = {
	{"say",&say,"Says [args]",GENERAL},
	{"quit",&quit, "Quits",ALL},
	{"list",&list, "List Commands",GENERAL},
	{"roll",&roll, "Roll a dice with [args] sides",GENERAL},
	{"flip",&flip, "Flips a coin",GENERAL},
	{"Mine",&Mine, " ",ELEVATED}
};
short COMMAND_LENGTH = 6; //ALWAYS CHANGE TO REFLECT ABOVE ^ //Maybe be made dynamic later on

void say(char *message)
{
	char *buff = malloc(strlen(message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+1);
	sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,message);
	printf("%s: %s\n",NickName,message);
	sendToServer(buff);
	free(buff);
}
void quit(char *ness)
{
	printf("%s :Leaving\n",COMMAND_STRINGS[7]);
	char *buff = malloc(255);
	sprintf(buff,"%s :Leaving\r\n",COMMAND_STRINGS[7]);
	sendToServer(buff);
	CONNECTED=0;
	QUIT=1;
	free(buff);
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
	char *buff=malloc(551); //Possible Overflow here....
	int len = 0;
	for(int i = 0; i < COMMAND_LENGTH; i++)
	{
		sprintf(buff,"[%s: %s] ",COMMANDS[i].text,COMMANDS[i].description);
	}
	say(buff);
	free(buff);
}
void rpn(char* args)
{
	//There will be another c file for this let me tell you....
}
void roll(char* arg)
{
	srand(time(NULL)); //PLANT THE SEEDS
	int num;
	if((num = atoi(arg)) > 0)
	{
		int num = rand() % atoi(arg); //Also Should work
		char *buff = malloc(255) + 1;
		sprintf(buff,"You Rolled %d",num);
		say(buff);
		free(buff);
	}
	else
	{
		char *buff = malloc(255);
		sprintf(buff,"Roll requires a positive integer");
		say(buff);
		free(buff);
	}
} 
void flip(char *ness)
{
	srand(time(NULL)); //PLANT THE SEEDS
	int num;
	if((num = rand() % 2 + 1) == 1)
	{
		say("Heads");
	}
	else
	{
		say("Tails");
	}
}
void Mine(char *ness)
{
	say("Literally found Hitler");
}

