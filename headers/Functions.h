#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../headers/client.h"
typedef void (*BotCommand)(char*);
typedef struct Command
{
	char *text;
	BotCommand func;
	char *description;
} Command;
typedef enum 
{
ALL,
ELEVATED,
GENERAL,
LIMITED,
NONE
} BOT_ACCESS;
typedef struct USER
{
	char *handle;
	BOT_ACCESS access;
} USER;
extern Command COMMANDS[];
void say(char *args);
void quit(char *args);
void list(char *args);
void pong(char *args);
void ping(char *args);
void tribotjacking(char *args); //see below
void rpn(char *args); //because why not
//zombie mode see above
#endif
