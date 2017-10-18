#include <stddef.h>
#include "deque.h"
#include "queue.h"

struct QueuePrivateFields {
	Deque deque;
};

Queue::Queue() {
	pf = new QueuePrivateFields;
}

Queue::~Queue() {
	delete pf;
}

void Queue::push(int data) {
	pf->deque.pushBack(data);
}

int Queue::get() {
	return pf->deque.getFront();
}

void Queue::pop() {
	pf->deque.popFront();
}

bool Queue::isEmpty() {
	return pf->deque.isEmpty();
}
