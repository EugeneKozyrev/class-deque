server:
	g++ -lws2_32 -o server server.cpp 

client:
	g++ -lws2_32 -o client client.cpp

clean:
	-rm "server.exe"
	-rm "client.exe"
