#include "pipe_networking.h"

void sighandler(int signo){
	if(signo == SIGINT){
		remove(WKP);
		exit(0);
	}
}

int main() {
	signal(SIGINT, sighandler);	
	int bytes = 0;
	int to_server = 0;
	int from_server = 0;

	from_server = client_handshake( &to_server );
	
	while(1){
		int recieved;
		bytes = read(from_server, &recieved, 4);
		if(bytes!=4){
			if(bytes==0)exit(0);
			err();
		}
		printf("recieved %d!\n", recieved);
	}
}
