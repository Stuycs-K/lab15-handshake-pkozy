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
		int to_client = 0;
		int from_client = 0;
		int bytes = 0;
		
		from_client = server_setup();
		fork();
		if(pid==0){
			//child
			server_handshake_half(*to_client, from_client);
		}
		
		while(1){
			srand(time(NULL));
			int send = rand()%100 + 1;
			bytes = write(to_client, &send, 4);
			if(bytes!=4){
				if(errno==32){break;}
				else{err();}
			}
			sleep(1);
		}
		
		close(to_client);
		close(from_client);
	}
}

