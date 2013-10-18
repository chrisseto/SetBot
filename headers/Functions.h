#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../headers/client.h"
#include "../headers/Structs.h"
#include "../headers/Variables.h"
#include <stdlib.h>
#include <time.h>

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

extern Command COMMANDS[];
extern short COMMAND_LENGTH; //Laziness is bestness
void say(char *args);
void quit(char *args);
void list(char *args);
void pong(char *args);
void getaccess(char *args);
void ping(char *args);
void roll(char *arg);
void flip(char *args);
void Mine(char *args);
void tribotjacking(char *args); //see below
void rpn(char *args); //because why not
//zombie mode see above
//stab
//set access
//help
//access required
#endif
