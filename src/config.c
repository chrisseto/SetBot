#include "../headers/config.h"
#include "../headers/Structs.h"

const char* Server = "chat.freenode.net";
const int Port = 8000;
const char* NickName = "SetBot";
const char* User = "SetBot SetBot SetBot SetBot";
const char* Pass = "none";
const char* Channel = "#stap-dev";
const int DEBUG = 1;

const char TRIGGER = '!';

USER ALLOWEDUSERS[] = {
	{"SetBack",ALL},
	{"Triclops256",ELEVATED}
};
