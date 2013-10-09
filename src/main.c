#include "../headers/client.h"
//TODO
//move sok into client.c to be static
//ie getNextLine()
//Make functions more comprehensive
//BeginLoop()

void main(int argc, char *args[])
{
	if(connectToServer() < 1)
	{
		return;
	}
	while(getNextLine() > 0)
	{
	}
	printf("Disconnected from host\n");
}
