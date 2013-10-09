#include "../headers/client.h"
//TODO
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
