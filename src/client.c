#include "../headers/client.h"

/*File client.c
Contains methods to connect to an Irc server and interact with it
C Sockets- Literally Hitler*/


static int sock;

int connectToServer()
{	
	struct sockaddr_in server;
	struct hostent *host;
	host = gethostbyname(Server);
	if(host == NULL)
	{
		printf("EROR: No such host\n");
		return 0;
	}
	memcpy(&server.sin_addr,host->h_addr_list[0],host->h_length);
	server.sin_family = AF_INET;
	server.sin_port = htons( Port );

	//creating socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if(sock < 0){
		printf("ERROR: Could not open socket\n");
		return 0;
	}
	
	if(connect(sock , (struct sockaddr *)&server , sizeof(server))< 0)
	{
		printf("ERROR: could not connect to server %d\n",errno);
		return 0;
	}
	//Time to send Nick etc.
	char buff[255];
	makeConnectionPhrase(buff);
	sendToServer(buff);
	printf("Connected!\n");
	return 1;
}
void makeConnectionPhrase(char *buff)
{
	sprintf(buff,"PASS %s\r\nNICK %s\r\nUSER %s\r\n",Pass,NickName,User);
}
//Might add in check for valid socket later... might...
int sendToServer(char* message)
{
	if(write(sock, message, strlen(message)) < 0)
	{
		printf("ERROR: Failed to write to socket %d\n",errno);
		return -1;
	}
	free(message);
	return 1;
}
int join()
{
	char buff[255];
	sprintf(buff,"%s %s\r\n",COMMAND_STRINGS[6],Channel);
	sendToServer(buff);
	if(DEBUG)
		printf("Sent join Command: %s",buff);
}
void parse(char *msg)
{

	if(DEBUG)
	{
		printf("%s\n",msg);
	}
	char *buff;
	char *chunk[5];
	buff = strtok(msg," ");
	chunk[0] = buff;
	buff = strtok(NULL," ");
	chunk[1] = buff;
	buff = strtok(NULL," ");
	chunk[2] = buff;
	buff = strtok(NULL,":\n");
	if(buff != NULL)
		chunk[3] = buff;

	if(!CONNECTED && strstr(chunk[1],"MODE"))
	{
		join();
		CONNECTED = 1;
	}
	if(strcmp(chunk[1],"PRIVMSG")==0)
	{
		if(chunk[3][0] == TRIGGER)
			if(DEBUG)
				printf("found command! %s\n",chunk[3]);
		parseUserCommand(chunk[3]);
			
	}
	if(strcmp(chunk[0], COMMAND_STRINGS[5])==0)
	{
		pong(chunk[3]);
	}
}
int getNextLine()
{
	char next,msg[551];
	int i = 0;
	while(read(sock,&next,1)>0 && i < 551)
	{
		if(next == '\n')
		{
			msg[i] = '\0';				
			parse(&msg);
			return 1;
		}
		else if(next != '\r')
		{
			msg[i] = next;
			i++;
		}
	}
	printf("Read 0 bytes from socket,Something went wrong\n");
	return -1;
}
void parseUserCommand(char* args)
{
	char *command = strtok(args," ");
	command++;
	args = strtok(NULL," ");
	printf("%s %s\n",command,args);
	if(strcmp(command,"say")==0)
	{
		say(args);
	}
	if(strcmp(command,"quit")==0)
	{
		quit(NULL);
	}
}


int disconnect()
{
	
}
int changeNick(char* nick)
{
}
int joinChannel(char* channel)
{
	
}
