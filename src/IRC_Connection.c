#include "../headers/IRC_Connection.h"

int connect_to_server(char *Server, int Port, char *Nick)
{
	//Loading up the IRC struct for later use
	strcpy(_server.server,*Server);
	_server.port = Port;
	strcpy(_server.nick, Nick);
	_server.pass = "none";
	char *buff = malloc((strlen(nick)+1)*4);
	sprintf(buff,"%s %s %s %s",Nick,Nick,Nick,Nick);
	strcpy(_server.user,buff);
	free(buff);
	//All loaded up

	//Creating socket and other networking black magic
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
	//<\black magic>

	//Sending information to join sever
	buff = malloc(strlen(pass)+strlen(nick)+strlen(user)+21);
	sprintf(buff,"PASS %s\r\nNICK %s\r\nUSER %s\r\n",_server.pass,_server.nick,_server.user);
	send_raw(buff);
	free(buff);
	if(DEBUG)
		printf("Connected to %s:%d\n",Server,Port);
	CONNECTED = 1;
	return 1;
}
int join_channel(char *channel)
{
	if(DEBUG)
		printf("Joining %s\n",Channel);
	char *buff = malloc(strlen(channel)+7);
	sprintf(buff,"JOIN %s\r\n",channel);
	send_raw(buff);
	free(buff);	
}
int send_raw(char *message)
{
	if(write(sock, message, strlen(message)) < 0)
	{
		printf("ERROR: Failed to write to socket %d\n",errno);
		return 0;
	}
	return 1;
}
void pong(char *arg)
{
	char *buff = malloc(strlen(arg) + 9);
	sprintf(buff,"PONG %s\r\n",arg);
	if(DEBUG) 
		printf("%s",buff);
	send_raw(buff);
	free(buff);
}
void read_line(char *buff)
{
	//read in line
	//chunk into irc_message
	//call call back
	//free things?
}
IRC_Message chunk_message(char* msg)
{
	IRC_M chunked;
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
	//Load up irc_m
}
//args TBA
Message_Type get_message_type(char *chunk1, char *chunk2)
{
	
}
