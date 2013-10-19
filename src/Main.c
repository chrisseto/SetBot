#include "../include/IRC_Connection.h"
#include "../include/Functions.h"
#include "../include/config.h"
#include "../include/Parse.h"

IRC bot; //Not the best choice but its happening

void main(int argc, char *args[])
{
	
	IRC_init(&bot,"chat.freenode.net",8000,"SetBot","none");//work in progress
	bot.Message_Recieved = &Message_Recieved;
	bot.Bot_Messaged = &Bot_Messaged;
	start_IRC_loop(&bot,Channel);
	printf("Disconnected from host\n");
}
