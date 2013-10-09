#ifndef CLIENT_H
#define CLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <error.h>
#include <errno.h>
#include  <netdb.h>
#include "../headers/Functions.h"
#include "../headers/config.h"
extern const char* COMMAND_STRINGS[];

//Exposed methods
int connectToServer();
void makeConnectionPhrase(char* buff);
int getNextLine();
//Non exposed methods
static int sendToServer(char* message);
int join();
void pong();
int getline();
void say(char *message);
int QUIT=0;
#endif
