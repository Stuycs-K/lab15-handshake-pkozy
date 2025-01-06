#include "pipe_networking.h"

void sighandler(int signo){
	if(signo == SIGINT){
		//remove(PP);
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
		char send[29] = "bho bup up booging bheir bop";
		bytes = write(to_server, &send, 29);
		if(bytes!=29){
			if(bytes==0)exit(0);
			err();
		}
		char recieved[29];
		bytes = read(from_server, &recieved, 29);
		if(bytes!=29)err();
		printf("%s\n", recieved);
		sleep(1);
	}
}
