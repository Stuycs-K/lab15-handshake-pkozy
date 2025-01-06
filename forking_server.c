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
		if(getpid()==0){
			//child
			server_handshake_half(&to_client, from_client);
			printf("finished handshake\n");
			while(1){
				char recieved[29];
				bytes = read(from_client, &recieved, 29);
				if(bytes!=29){
					if(errno==32){break;}
					else{err();}
				}
				//strfry without getting the \n in there ruinign it
				recieved[29] = ' ';
				strfry(recieved);
				recieved[29] = '\n';
				
				bytes = write(to_client, &recieved, 29);
			}			
		}
		
		close(to_client);
		close(from_client);
	}
}

