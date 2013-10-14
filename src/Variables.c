#include "../headers/Variables.h"

int QUIT = 0;
int CONNECTED = 0;
const int DEBUG = 1;
const char* COMMAND_STRINGS[] = {
	"PRIVMSG", //0
	"PASS", //1
	"NICK", //2
	"USER", //3
	"PING", //4
	"PONG", //5
	"JOIN", //6
	"QUIT" //7
};
