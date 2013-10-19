#ifndef SECURITY_H
#define SECURITY_H

extern const int REGISTEREDUSERS;

typedef enum 
{
ALL = 4,
ELEVATED = 3,
GENERAL = 2,
LIMITED = 1,
NONE = 0
} BOT_ACCESS;

typedef struct USER
{
	char *handle;
	BOT_ACCESS access;
} USER;


extern USER ALLOWEDUSERS[];

BOT_ACCESS getUserControl(char *name);

#endif
