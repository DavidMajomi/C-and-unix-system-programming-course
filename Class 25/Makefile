all: annoy byteorder client forksignal ignoresignal seesignal server simpleclient simpleloop simpleserver strikes tcp_client tcp_server

annoy: annoy.c
	gcc annoy.c -o annoy

byteorder: byteorder.c 
	gcc byteorder.c -o byteorder

client: client.c
	gcc client.c -o client

forksignal: forksignal.c
	gcc forksignal.c -o forksignal

ignoresignal: ignoresignal.c
	gcc ignoresignal.c -o ignoresignal

seesignal: seesignal.c
	gcc seesignal.c -o seesignal

server: server.c 
	gcc server.c -o server 

simpleclient: simpleclient.c 
	gcc simpleclient.c -o simpleclient

simpleloop: simpleloop.c
	gcc simpleloop.c -o simpleloop

simpleserver: simpleserver.c 
	gcc simpleserver.c -o simpleserver

strikes: strikes.c
	gcc strikes.c -o strikes

tcp_client: tcp_client.c 
	gcc tcp_client.c -o tcp_client

tcp_server: tcp_server.c 
	gcc tcp_server.c -o tcp_server

clean: 
	rm -f annoy byteorder client forksignal ignoresignal seesignal server simpleclient simpleloop  simpleserver strikes tcp_client tcp_server

.PHONY: clean
