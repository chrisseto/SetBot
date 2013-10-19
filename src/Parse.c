#include "../include/Parse.h"

void Message_Recieved(IRC_Message *msg)
{
	//printf("%s: %s\n",msg->sender,msg->message);
	if(msg->message[0]==TRIGGER)
	{
		printf("Recieved command %s from %s\n",msg->message+1,msg->sender);
		char *command;
		//strcpy(command,msg->message);
		command = strtok(msg->message," ");
		command++;
		for(int i = 0; i < COMMAND_LENGTH; i++)
		{
			if(strcmp(COMMANDS[i].text,command)==0)
			{
				if(getUserControl(msg->sender) >= COMMANDS[i].security)
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


