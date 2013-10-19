#include "../include/Parse.h"

void Message_Recieved(IRC_Message *msg)
{
	//printf("%s: %s\n",msg->sender,msg->message);
	if(msg->message[0]==TRIGGER)
	{
		char *comand;
		strcpy(comand,msg->message);
		char *command = strtok(comand," ");
		msg->message += strlen(command) + 1;
		command++;
		printf("Recieved command %s: %s from %s\n",command,msg->message,msg->sender);
		for(int i = 0; i < COMMAND_LENGTH; i++)
		{
			if(strcmp(COMMANDS[i].text,command)==0)
			{
				//if(getUserControl(msg->sender) >= COMMANDS[i].security)
					COMMANDS[i].func(msg);
				//Lack of security message?
				break;
			}
		}
	}
}

void Bot_Messaged(IRC_Message *msg)
{
	//Still needs to be implemented
}


