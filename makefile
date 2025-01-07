compile: clientcomp servercomp
clientcomp: basic_client.o pipe_networking.o
	gcc -o clientex basic_client.o pipe_networking.o
	
servercomp: forking_server.o pipe_networking.o
	gcc -o serverex forking_server.o pipe_networking.o
	
basic_client.o: basic_client.c pipe_networking.h
	gcc -c basic_client.c
	
forking_server.o: forking_server.c pipe_networking.h
	gcc -c forking_server.c
	
pipe_networking.o: pipe_networking.c pipe_networking.h
	gcc -c pipe_networking.c
client: clientex
	@./clientex
server: serverex
	@./serverex
	
clean:
	rm *.o 
	rm *~
