#include "pipe_networking.h"

void sighandler(int signo){
	if(signo == SIGINT){
		remove(WKP);
		exit(0);
	}

}

int main() {
	signal(SIGINT, sighandler);
	signal(SIGPIPE, SIG_IGN);
	while(1){
		printf("new client\n");
		int to_client = 0;
		int from_client = 0;
		int bytes = 0;
		
		from_client = server_handshake( &to_client );
		
		while(1){
			srand(time(NULL));
			int send = rand()%100 + 1;
			printf("fd: %d\n", to_client);
			bytes = write(to_client, &send, 4);
			printf("write done\n");
			if(bytes!=4){
				if(errno==32){break;}
				else{err();}
			}
			sleep(1);
		}
		
		printf("done with this client\n");
		close(to_client);
		close(from_client);
	}
}

