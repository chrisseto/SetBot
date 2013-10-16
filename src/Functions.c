#include "../headers/Functions.h"

Command COMMANDS[] = {
	{"say",&say,"Says [args]",GENERAL},
	{"quit",&quit, "Quits",ALL},
	{"list",&list, "List Commands",GENERAL},
	{"roll",&roll, "Roll a dice with [args] sides",GENERAL},
	{"flip",&flip, "Flips a coin",GENERAL},
	{"Mine",&Mine, "",ELEVATED},
	{"access",&getaccess,"Returns UAC",NONE}
};
short COMMAND_LENGTH = 7; //ALWAYS CHANGE TO REFLECT ABOVE ^ //Maybe be made dynamic later on

void say(char *message)
{
	if(strcmp(message,"")!=0)
	{
		char *buff[strlen(message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+4];
		sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,message);
		printf("%s: %s\n",NickName,message);
		sendToServer(buff);
	}
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
	char buff[551]; //Possible Overflow here.... also doesnt like malloc
	int len = 0;
	for(int i = 0; i < COMMAND_LENGTH; i++)
	{
		sprintf(buff + len,"[%s: %s] ",COMMANDS[i].text,COMMANDS[i].description);
		len+=(strlen(buff)-len); //Haha! clever math... also meta
	}
	say(buff);
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
		int num = (rand() % atoi(arg)) + 1; //Also Should work
		char *buff = malloc(255);
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
void getaccess(char *arg)
{
	char *buff = malloc(256);
	sprintf(buff,"%s: ",arg);
	switch(getUserControl(arg))
	{
		case 0:
			sprintf(buff+strlen(arg)+2,"NONE");
			break;
		case 1:
			sprintf(buff+strlen(arg)+2,"LIMITED");
			break;
		case 2:
			sprintf(buff+strlen(arg)+2,"GENERAL");
			break;
		case 3:
			sprintf(buff+strlen(arg)+2,"ELEVATED");
			break;
		case 4:
			sprintf(buff+strlen(arg)+2,"ALL");
			break;
	}
	say(buff);
	free(buff);
}

