#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

fd_set read_fd, write_fd, fds;
char read_buffer[200000], write_buffer[200000], *msg[200000];
int clients = 0, fd_max = 0, id=[200000];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_msg(int connfd, char *write_buffer){
	for (int i = 0; i <= fd_max; i++)
		if (FD_ISSET(i, &write_buffer) && i != connfd)
			send(i, write_buffer, strlen(write_buffer), 0)
}

int main(int arg_c, char **arg_v) {
	if (arg_c != 2){
		 write(2, "Wrong number of arguments", 26);
		 exit (1);
	}

	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		write(2, "Fatal error\n", 12); 
		exit(0); 
	} 
	
	FD_ZERO(&fds);
	fd_max = sockfd;
	FD_SET(fd_max, &fds);
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(arg_v[1]); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		write(2, "Fatal error\n", 12); 
		exit(0); 
	} 
	
	if (listen(sockfd, 10) != 0) {
		write(2, "Fatal error\n", 12); 
		exit(0); 
	}

	while (1){
		read_fd = write_fd = fds;
		if (select(fd_max + 1, &read_fd, &write_fd, NULL, NULL) < 0){
			write(2, "Fatal error\n", 12);
			exit(0);
		}
		for(int i = 0; i <= fd_max; i++){
			if (!FD_ISSET(i, &read_fd))
				continue;
			if (i == sockfd) {
				len = sizeof(servaddr);
				connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (connfd >= 0){
					if (connfd > fd_max)
						fd_max = connfd;
					id[connfd] = clients++;
					msg[connfd] = NULL;
					FD_SET(connfd, &fds);
					sprintf(write_buffer, "server: client %d just arrived\n", id[connfd]);
					send_msg(connfd, write_buffer);
					break;
				}
			} else {
				int recv_len = recv(i, read_buffer, 6000, 0):
				if (recv_len <= 0){
					sprintf(write_buffer, "server: client %d just left\n", id[i]);
					send_msg(i, write_buffer);
					FD_CLR(i, &fds);
					free(msg[i]);
					msg[i] = NULL;
					close(i);
					break;
				}
				char *s;
				read_buffer[recv_len] = '\0';
				msg[i] = str_join(msg[i], read_buffer);
				while (extract_message(&(msg[i]), &s)){
					sprintf(write_buffer, "client %d: ", id[i]);
					send_msg(i, write_buffer);
					send_msg(i, s);
					free(s);
					s = NULL;
				}
			}
		}
	}
}