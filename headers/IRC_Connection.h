#ifndef IRC_CONNECTION_H
#define IRC_CONNECTION_H
//Everything will return 1 on success and 0 on failure
#define MAXHOOKS 5

typedef enum
{
PRVMSG = 0.
PING = 1,
KICK = 2,
MODE = 3,
NOTICE = 4,
MOTD = 5
} Message_Type;

typedef struct IRC_Channel
{
	char *channel;
	char *users[]; //Could be a big string
} IRC_Channel;

typedef struct IRC_Message
{
	IRC_Channel *orgin;
	char *sender;
	char *message;
} IRC_Message;

typedef struct IRC
{
	char *server;
	int port;
	int socket;
	char *pass;
	char *nick;
	char *user;
	int connected;
	IRC_Channel *channels[];
	void (*Message_Recieved)(IRC_Message*);
	void (*Bot_Messaged)(IRC_Message*);
} IRC;

int connect_to_server(char *server, int port);
int join_channel(char *channel);
void message_recieved();
int send_raw(char *message);
int send_messge(char *message);
int get_next_line(char *buffer, int buffer_size);


#endif 
