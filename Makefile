SERV_OBJS := Lock.o LockServer.o
CLNT_OBJS := Lock.o LockClient.o

all:

lserver: $(SERV_OBJS) 
	g++ $(SERV_OBJS) -o lserver

lclient: $(CLNT_OBJS)
	g++ $(CLNT_OBJS) -o lclient 

clean:
	rm *.o
	rm lserver lclient

LockServer.o: Lock.o LockServer.cpp
	g++ -c LockServer.cpp

LockClient.o: Lock.o LockClient.cpp
	g++ -c LockClient.cpp

Lock.o: Lock.h Lock.cpp
	g++ -c Lock.cpp -o Lock.o

