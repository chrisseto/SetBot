#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../headers/client.h"
typedef void (*BotCommand)(char*);
typedef struct Command
{
	char *text;
	BotCommand func;
} Command;
extern Command COMMANDS[];
void say(char *args);
void quit(char *args);
void list(char *args);
void pong(char *args);
void ping(char *args);
void tribotjacking(char *args);
#endif
