#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "../headers/client.h"
#include "../headers/Structs.h"
#include "../headers/Variables.h"
#include <stdlib.h>

extern Command COMMANDS[];
extern short COMMAND_LENGTH; //Laziness is bestness
void say(char *args);
void quit(char *args);
void list(char *args);
void pong(char *args);
void ping(char *args);
void roll(char *arg);
void flip(char *args);
void Mine(char *args);
void tribotjacking(char *args); //see below
void rpn(char *args); //because why not
//zombie mode see above
#endif
