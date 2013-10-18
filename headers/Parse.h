#ifndef PARSE_H
#define PARSE_H

#include "IRC_Connection.h"
#include "Security.h"
#include "config.h"
#include "Functions.h"

void Message_Recieved(IRC_Message *msg);
void Bot_Messaged(IRC_Message *msg);
#endif
