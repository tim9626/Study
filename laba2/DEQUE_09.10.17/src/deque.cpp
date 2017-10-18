#include <stddef.h>
#include "deque.h"

struct Element {
	int data;
	Element* prev = NULL;
	Element* next = NULL;
};

struct DequePrivateFields {
	Element* first = NULL;
	Element* last = NULL;
};

Deque::Deque() {
	pf = new DequePrivateFields;
}

Deque::~Deque() {
	Element* i = pf->first;
	while (i) {
		Element* tmp = i;
		i = i->next;
		delete tmp;
	}
	delete pf;
}

void Deque::pushBack(int data) {
	Element* e = new Element;
	e->data = data;
	if (!pf->first) {
		pf->first = e;
		pf->last = e;
	} else {
		e->prev = pf->last;
		pf->last = e;
		e->prev->next = e;
	}
}

void Deque::pushFront(int data) {
	Element* e = new Element;
	e->data = data;
	if (!pf->first) {
		pf->first = e;
		pf->last = e;
	} else {
		e->next = pf->first;
		pf->first = e;
		e->next->prev = e;
	}
}

void Deque::popBack() {
	if (!pf->first) {
		return;
	}
	if (pf->first == pf->last) {
		delete pf->first;
		pf->first = NULL;
		pf->last = NULL;
	} else {
		Element* tmp = pf->last;
		pf->last = pf->last->prev;
		pf->last->next = NULL;
		delete tmp;
	}
}

void Deque::popFront() {
	if (!pf->first) {
		return;
	}
	if (pf->first == pf->last) {
		delete pf->first;
		pf->first = NULL;
		pf->last = NULL;
	} else {
		Element* tmp = pf->first;
		pf->first = pf->first->next;
		pf->first->prev = NULL;
		delete tmp;
	}
}

int Deque::getBack() {
	if (pf->last) {
		return pf->last->data;
	} else {
		return 0;
	}
}

int Deque::getFront() {
	if (pf->first) {
		return pf->first->data;
	} else {
		return 0;
	}
}

bool Deque::isEmpty() {
	return pf->first == NULL;
}
