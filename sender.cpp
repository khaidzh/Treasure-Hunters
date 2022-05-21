#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>

using namespace std;

int sender(char* msg)
{
	int sockid;
	struct sockaddr_in addr;
	//char msg[] = "Sender\n";
	char servaddr[] = "192.168.31.242";
	sockid = socket(AF_INET, SOCK_DGRAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1985);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	inet_aton(servaddr, &addr.sin_addr);

	sendto(sockid, msg, 122, 0, (struct sockaddr *) &addr, sizeof(addr));

	return 0;
}

