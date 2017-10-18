#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	Queue();
	~Queue();
	void push(int data);
	int get();
	void pop();
	bool isEmpty();
private:
	struct QueuePrivateFields *pf;
};

#endif
