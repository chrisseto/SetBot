#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "IRC_Connection.h"
#include "Security.h"
#include "config.h"
#include <stdlib.h>
#include <time.h>

extern IRC bot; //This is pretty ugly but it will work for now

typedef void (*BotCommand)(IRC_Message*);

typedef struct Command
{
	char *text;
	BotCommand func;
	char *description;
	BOT_ACCESS security;
} Command;

extern Command COMMANDS[];
extern short COMMAND_LENGTH; //Laziness is bestness

void say(IRC_Message *message);
void quit(IRC_Message *message);
void list(IRC_Message *message);
void getaccess(IRC_Message *message);
void ping(IRC_Message *message);
void roll(IRC_Message *message);
void flip(IRC_Message *message);
void Mine(IRC_Message *message);
void tribotjacking(IRC_Message *message); //see below
void rpn(IRC_Message *message); //because why not
//zombie mode see above
//stab
//set access
//help
//access required
#endif
