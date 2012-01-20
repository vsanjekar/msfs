#include <iostream>

#include <cstdlib>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Lock.h"

using namespace std;

class LockServer{
	string serverIP;
	int server_fd;

	public:
	void init(string s);
	void createLock();
};

void LockServer::init(string sIP){

	struct sockaddr_in serverAddr, clientAddr;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int client_fd;

	serverIP = sIP;
	cout<<serverIP<<endl;

	/* 
	 * Create server socket.
	 */
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		cout<<"Error creating server socket!"<<endl;
	}
	cout<<"created server socket!"<<endl;

	bzero(&serverAddr, sizeof(struct sockaddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(65000);
	//serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);

	if((bind(server_fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr))) == -1) {
		cout<<"Error binding server socket!"<<endl;
	}
	cout<<"bound server socket!"<<endl;
	if((listen(server_fd, 10)) == -1){
		cout<<"Error listening server socket!"<<endl;
	}
	cout<<"listening server socket!"<<endl;

	while(1){
		if((client_fd = accept(server_fd, (struct sockaddr *)&clientAddr, &addrlen))=-1){
			cout<<"Error accepting client socket!"<<endl;
		}
		cout<<"Received client socket!"<<endl;
	}
}

void LockServer::createLock(){

	Lock *l = new Lock();
}

int main(int argc, char **argv){

	string sIP;

	if(argc != 2){
		cout<<"Usage: lserver <IP>"<<endl;
		exit(0);
	}

	sIP = argv[1];

	/*
	 * Start the Lockserver.
	 */
	LockServer *ls = new LockServer();
	ls->init(sIP);
	ls->createLock();
	return 0;
}

