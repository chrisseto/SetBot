#include "../headers/IRC_Connection.h"
#include "../headers/config.h"

//TODO
//Make functions more comprehensive
//BeginLoop()
//FIX ARG PARSING
//cuts off at first space...
void main(int argc, char *args[])
{
	IRC bot;
	IRC_init(&bot,Server,Port,Nick,Pass);
	bot.Message_Recieved = &Message_Recieved;
	bot.Bot_Messaged = &Bot_Messaged;
	Start_IRC_Loop(&bot,Channel);
	printf("Disconnected from host\n");
}
