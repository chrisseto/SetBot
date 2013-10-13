#include "../headers/config.h"
const char* Server = "chat.freenode.net";
const int Port = 8000;
const char* NickName = "SetBot";
const char* User = "SetBot SetBot SetBot SetBot";
const char* Pass = "none";
const char* Channel = "#wutwut";
const int DEBUG = 1;
const extern char* ALLOWEDUSERS[];
const char TRIGGER = '!';
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
const char* ALLOWEDUSERS[] = {
	"SetBack"
};
