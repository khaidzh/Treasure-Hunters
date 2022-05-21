#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

char* receiver()
{
	int sockid;
	struct sockaddr_in addr;
	char* buf = (char*)malloc(122);
	int bytes_read;
	char servaddr[] = "172.24.90.137";
	sockid = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1985);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_aton(servaddr, &addr.sin_addr);
	bind(sockid, (struct sockaddr *) &addr, sizeof(addr));
	bytes_read = recvfrom(sockid, buf, 122, 0, NULL, NULL);
	buf[bytes_read] = '\0';

	return buf;
	//printf("%s", buf);
}
