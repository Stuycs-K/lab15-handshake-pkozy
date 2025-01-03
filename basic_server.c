#include "pipe_networking.h"

int main() {
	int to_client;
	int from_client;
	int bytes;

	from_client = server_handshake( &to_client );
	
	while(1){
		srand(time(NULL));
		int send = rand()%100 + 1;
		bytes = write(to_client, &send, 4);
		if(bytes!=4)err();
		sleep(1);
	}
}
