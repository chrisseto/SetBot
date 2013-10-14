#ifndef STRUCTS_H
#define STRUCTS_H
typedef void (*BotCommand)(char*);

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

typedef struct Command
{
	char *text;
	BotCommand func;
	char *description;
	BOT_ACCESS security;
} Command;
#endif
