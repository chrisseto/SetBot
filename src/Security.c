#include "../headers/Security.h"

BOT_ACCESS getUserControl(char *name)
{
	for(int i = 0; i < REGISTEREDUSERS; i++)
	{
		if(strcmp(ALLOWEDUSERS[i].handle,name)==0)
			return ALLOWEDUSERS[i].access;
	}
	return GENERAL;
}
