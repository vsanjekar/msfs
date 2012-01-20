#include <iostream>

#include <cstdlib>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Lock.h"

using namespace std;

class LockClient{
	string serverIP;

	public:
        void init(string s);

};

void LockClient::init(string sIP){

	int sock_fd;
	serverIP = sIP;
	struct sockaddr_in serverAddr;

	if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
                cout<<"Error creating server socket!"<<endl;
        }
        cout<<"created socket!"<<endl;
	
	bzero(&serverAddr, sizeof(struct sockaddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(65000);
        //serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);

	if((connect(sock_fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr))) == -1){
                cout<<"Error connecting server socket!"<<endl;
	}
	cout<<"Connected to server socket!"<<endl;

}

int main(int argc, char **argv){

	string sIP;
	LockClient *lc = new LockClient();

        if(argc != 2){
                cout<<"Usage: lclient <server IP>"<<endl;
                exit(0);
        }

        sIP = argv[1];

	lc->init(sIP);
}
