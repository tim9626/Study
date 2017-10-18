#ifndef DEQUE_H_
#define DEQUE_H_

class Deque {
public:
	Deque();
	~Deque();
	void pushBack(int data);
	void pushFront(int data);
	int getBack();
	int getFront();
	void popBack();
	void popFront();
	bool isEmpty();
private:
	struct DequePrivateFields *pf;
};

#endif
