#include "../headers/client.h"
/*File client.c
Contains methods to connect to an Irc server and interact with it
C Sockets- Literally Hitler*/


static int sock; //The socket descriptor (gasp) no one else gets to see it

int connectToServer()
{	
	//Yuck structs this was god awful
	//People for Hitler, Networking structs for me
	//watch out [insert some ethnic group here]
	struct sockaddr_in server;
	struct hostent *host;
	host = gethostbyname(Server);
	//Null checks.... cause... you know
	if(host == NULL)
	{
		printf("EROR: No such host\n"); //we dont need no errno
		return 0;
	}
	memcpy(&server.sin_addr,host->h_addr_list[0],host->h_length);
	server.sin_family = AF_INET;
	server.sin_port = htons( Port );

	//creating socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if(sock < 0){
		printf("ERROR: Could not open socket %d\n",errno);
		return 0;
	}
	
	if(connect(sock , (struct sockaddr *)&server , sizeof(server))< 0)
	{
		printf("ERROR: could not connect to server %d\n",errno);
		return 0;
	}
	//Time to send Nick etc.
	char buff[255]; //This could be less but currently not an issue.... even worse could be more
	makeConnectionPhrase(buff);
	sendToServer(buff);
	printf("Connected to %s:%d\n",Server,Port);
	return 1;
} 
void makeConnectionPhrase(char *buff)
{
	//Pretty straight forward here
	sprintf(buff,"PASS %s\r\nNICK %s\r\nUSER %s\r\n",Pass,NickName,User);
}
//Might add in check for valid socket later... might... Or if connected.... yeah that could work
int sendToServer(char* message)
{
	if(write(sock, message, strlen(message)) < 0)
	{
		printf("ERROR: Failed to write to socket %d\n",errno);
		return -1;
	}
	return 1;
}
int join()
{
	char buff[255]; //This could also be smaller, unlike my friend group
	sprintf(buff,"%s %s\r\n",COMMAND_STRINGS[6],Channel);
	sendToServer(buff);
	if(DEBUG)
		printf("Joining %s\n",Channel);
}
void parse(char *msg)
{
	char *buff;
	char *chunk[5];
	buff = strtok(msg," ");
	chunk[0] = buff;
	buff = strtok(NULL," ");
	chunk[1] = buff;
	buff = strtok(NULL," ");
	chunk[2] = buff;
	buff = strtok(NULL,"\n");
	if(buff != NULL)
		chunk[3] = buff;
	if(!CONNECTED && strstr(chunk[1],"MODE"))
	{
		join();
		CONNECTED = 1;
	}
	if(strcmp(chunk[0],COMMAND_STRINGS[4])==0)
	{
		pong(chunk[1]);//This may be wrong... Will fix later (if broken)
	}
	if(strcmp(chunk[1],COMMAND_STRINGS[0])==0)
	{
		char *nick = strtok(chunk[0],"!"); //Maybe Right... hmm
		printf("%s: %s\n",nick,chunk[3]+2);
		if(chunk[3][1] == TRIGGER)
		{
			parseUserCommand(chunk[3]);
		}
			
	}
	if(strcmp(chunk[0], COMMAND_STRINGS[5])==0)
	{
		pong(chunk[3]);
	}
}
int getNextLine()
{
	char next;
	char msg[551];
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
	//This function needs to be more refined
	printf("Read 0 bytes from socket,Something went wrong\n");
	return -1;
}
void parseUserCommand(char* args)
{
	char *backup = malloc(strlen(args)+1);
	//memset(backup,0,strlen(args)+1); Shouldn't be needed all space is being written too.
	memcpy(backup,args,strlen(args)+1); //Could use strcpy here..... I might at some point in time
	char *command = strtok(args," "); //FIX ME IM A DICK AND CUT OFF ALL THE SPACES
	command+=2; //trims :[TRIGGER] leaving raw command
	backup+=strlen(command)+3; //Removes :[TRIGGER][COMMAND][SPACE]
	//printf("Command %s Backup %s %d\n",command,backup,strlen(backup)); Was for debugging Might add back in
	for(int i = 0; i < 4; i++) //Yeah.... need to fix this sizes... Const int maybe? short would be a bit less over head
	{
		if(strcmp(COMMANDS[i].text,command)==0)
		{
			COMMANDS[i].func(backup);
			break;
		}
	}
	free(backup-strlen(command)-3); //Get the original pointer back to properly free() the memory
}
