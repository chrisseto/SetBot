#ifndef CLIENT_H
#define CLIENT_H
#include "../headers/Functions.h"
#include "../headers/config.h"
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
void makeConnectionPhrase(char* buff);
int getNextLine();
int sendToServer(char* message);
int join();
int getline();
void parseUserCommand(char* args);

#endif
