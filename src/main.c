#include "../headers/Functions.h"
#include "../headers/config.h"
#include "../headers/Parse.h"

IRC bot; //Not the best choice but its happening

void main(int argc, char *args[])
{
	
	IRC_init(&bot,"chat.freenode.net",8000,"SetBot","none");//work in progress
	bot.Message_Recieved = &Message_Recieved;
	bot.Bot_Messaged = &Bot_Messaged;
	Start_IRC_Loop(&bot,Channel);
	printf("Disconnected from host\n");
}
