#include "../headers/Parse.h"

void Message_Recieved(IRC_Message *msg)
{
	if(msg->message[0]==TRIGGER)
	{
		for(int i = 0; i < COMMAND_LENGTH; i++)
		{
			if(strcmp(COMMANDS[i].text,(msg->message+1))==0)
			{
				if(getUserControl(msg->sender) >= COMMANDS[i].security)
					COMMANDS[i].func(msg);
				break;
			}
		}
	}
}

void Bot_Messaged(IRC_Message *msg)
{
	//Still needs to be implemented
}

BOT_ACCESS getUserControl(char *name)
{
	for(int i = 0; i < REGISTEREDUSERS; i++)
	{
		if(strcmp(ALLOWEDUSERS[i].handle,name)==0)
			return ALLOWEDUSERS[i].access;
	}
	return GENERAL;
}
