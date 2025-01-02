#include "pipe_networking.h"

int main() {
	int bytes;
	int to_server;
	int from_server;

	from_server = client_handshake( &to_server );
	printf("handshake done\n");	
	
	while(1){
		int recieved;
		bytes = read(from_server, &recieved, 4);
		if(bytes!=4)err();
		printf("recieved %d!\n", recieved);
	}
}
