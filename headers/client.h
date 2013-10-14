#ifndef CLIENT_H
#define CLIENT_H
#include "../headers/Functions.h"
#include "../headers/config.h"
#include "../headers/Structs.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>


extern const char* COMMAND_STRINGS[];

int connectToServer();
static void makeConnectionPhrase(char* buff);
int getNextLine();
int sendToServer(char* message);
static int join();
static int getline();
static void parseUserCommand(char* args, char* user);
BOT_ACCESS getUserControl(char *name);
#endif
