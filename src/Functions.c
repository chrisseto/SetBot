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

void say(IRC_Message *msg)
{
	if(strcmp(msg->message,"")!=0)
	{
		char *buff[strlen(msg->message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+4];
		sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],Channel,msg->message);
		printf("%s: %s\n",NickName,msg->message);
		sendToServer(buff);
	}
}
void quit(IRC_Message *msg) //change to Circ quit
{
	printf("%s :Leaving\n",COMMAND_STRINGS[7]);
	char *buff = malloc(255);
	sprintf(buff,"%s :Leaving\r\n",COMMAND_STRINGS[7]);
	sendToServer(buff);
	CONNECTED=0;
	QUIT=1;
	free(buff);
}
void pong(IRC_Message *msg) //can be removed
{
	char *buff = malloc(strlen(arg)+5);
	sprintf(buff,"PONG %s\r\n",arg+1);
	printf("%s",buff);
	sendToServer(buff);
	free(buff);
}
void list(IRC_Message *msg)
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
void rpn(IRC_Message *msg)
{
	//There will be another c file for this let me tell you....
}
void roll(IRC_Message *msg)
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
void flip(IRC_Message *msg)
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
void Mine(IRC_Message *msg)
{
	say("Literally found Hitler");
}
void getaccess(IRC_Message *msg)
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

