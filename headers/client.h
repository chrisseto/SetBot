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
int sendToServer(char* message);
int join();
int getline();
static int QUIT = 0;
static int CONNECTED = 0;
#endif
