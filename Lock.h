/*
 * Lock.h
 */

class Lock {
	std::string name;
	Lock();
	// Only server should be able to create a Lock
	friend class LockServer;
};
