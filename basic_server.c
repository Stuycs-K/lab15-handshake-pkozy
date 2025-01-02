#include "pipe_networking.h"

int main() {
	int to_client;
	int from_client;
	int bytes;

	from_client = server_handshake( &to_client );
	
	printf("handshake done\n");
	while(1){
		srand(time(NULL));
		int send = rand()%100 + 1;
		bytes = write(to_client, &send, 4);
		if(bytes!=4)err();
		printf("sent %d!\n", send);
		sleep(1);
	}
}
