#ifndef IRC_CONNECTION_H
#define IRC_CONNECTION_H
static int sock,CONNECTED;
static char *channel[];
int connect_to_server(char *server, int port);
int join_channel(char *channel);
void message_recieved();
int send_raw(char *message);
int send_messge(char *message);
int get_next_line(char *buffer, int buffer_size);


#endif 
