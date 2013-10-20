#include "../include/Functions.h"

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

const char* COMMAND_STRINGS[] = {
	"PRIVMSG", //0
	"PASS", //1
	"NICK", //2
	"USER", //3
	"PING", //4
	"PONG", //5
	"JOIN", //6
	"QUIT" //7
};

void say(IRC_Message *msg)
{
	if(strcmp(msg->message,"")!=0)
	{
		char buff[strlen(msg->message)+strlen(Channel)+strlen(COMMAND_STRINGS[0])+4];
		sprintf(buff,"%s %s :%s\r\n",COMMAND_STRINGS[0],msg->target,msg->message);
		printf("%s: %s\n",NickName,msg->message);
		send_raw(&bot,buff);
	}
}
void quit(IRC_Message *msg)
{
	IRC_quit(&bot,"Leaving");
}
void list(IRC_Message *msg)
{
	char buff[551]; //Possible Overflow here.... also doesnt like malloc
	int len = 0;
	for(int i = 0; i < COMMAND_LENGTH; i++)
	{
		snprintf(buff + len,551,"[%s: %s] ",COMMANDS[i].text,COMMANDS[i].description);
		len+=(strlen(buff)-len); //Haha! clever math... also meta
	}
	say_to_channel(&bot,Channel,buff);
}
void rpn(IRC_Message *msg)
{
	//There will be another c file for this let me tell you....
}
void roll(IRC_Message *msg)
{
	srand(time(NULL)); //PLANT THE SEEDS
	int num;
	if((num = atoi(msg->message)) > 0)
	{
		num = (rand() % num) + 1; //Also Should work
		char *buff = malloc(255);
		sprintf(buff,"You Rolled %d",num);
		say_to_channel(&bot,Channel,buff);
		free(buff);
	}
	else
	{
		char *buff = malloc(255);
		sprintf(buff,"Roll requires a positive integer");
		say_to_channel(&bot,Channel,buff);
		free(buff);
	}
} 
void flip(IRC_Message *msg)
{
	srand(time(NULL)); //PLANT THE SEEDS
	int num;
	if((num = rand() % 2 + 1) == 1)
	{
		say_to_channel(&bot,Channel,"Heads");
	}
	else
	{
		say_to_channel(&bot,Channel,"Tails");
	}
}
void Mine(IRC_Message *msg)
{
	say_to_channel(&bot,Channel,"Literally found Hitler");
}
void getaccess(IRC_Message *msg)
{
	char *buff = malloc(256);
	sprintf(buff,"%s: ",msg->sender);
	switch(getUserControl(msg->sender))
	{
		case 0:
			sprintf(buff+strlen(msg->sender)+2,"NONE");
			break;
		case 1:
			sprintf(buff+strlen(msg->sender)+2,"LIMITED");
			break;
		case 2:
			sprintf(buff+strlen(msg->sender)+2,"GENERAL");
			break;
		case 3:
			sprintf(buff+strlen(msg->sender)+2,"ELEVATED");
			break;
		case 4:
			sprintf(buff+strlen(msg->sender)+2,"ALL");
			break;
	}
	say_to_channel(&bot,Channel,buff);
	free(buff);
}

