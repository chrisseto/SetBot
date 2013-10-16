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

typedef struct IRC_Message
{
	Message_Type type;
	char *sender;
	char *message;
} IRC_Message;

typedef struct IRC
{
	char *server;
	int port;
	char *pass;
	char *nick;
	char *user;
} IRC;

typedef void (*IRCcallback)(IRC_Message*);

static IRC _server;
static int sock,CONNECTED;

static IRCcallback[] callbacks; 

int connect_to_server(char *server, int port);
int join_channel(char *channel);
void message_recieved();
int send_raw(char *message);
int send_messge(char *message);
int get_next_line(char *buffer, int buffer_size);


#endif 
