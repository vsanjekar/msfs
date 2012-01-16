#include <iostream>

#include "Lock.h"

using namespace std;

class LockServer{
	public:
	void init();
	void start();
	void createLock();
};

void LockServer::init(){
}

void LockServer::start(){
	createLock();
}

void LockServer::createLock(){

	Lock *l = new Lock();
}

int main(){

	/*
	 * Start the Lockserver.
	 */
	LockServer *ls = new LockServer();
	ls->init();
	ls->start();
	return 0;
}

