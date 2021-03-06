#pragma once

#include <iostream>
#include <exception>
#include <assert.h>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* pNext;
	Node(T, Node* = NULL);
};

template <typename T>
Node<T>::Node(T _data, Node* _pNext) {
	this->data = _data;
	this->pNext = _pNext;
}

template <typename T>
class Queue {

public:
	Queue();
	Queue(Queue const & other);
	Queue& operator=(Queue const & other);
	~Queue();

public:
	bool enqueue(T const & elem);
	bool dequeue();
	T head() const;

	bool isEmpty() const;

private:
	void init();
	void copy(Queue const & other);
	void clean();

private:
	Node<T>* pFront;
	Node<T>* pBack;
	size_t size;
};

template <typename T>
Queue<T>::Queue() {
	init();
}

template <typename T>
void Queue<T>::init() {
	this->pFront = NULL;
	this->pBack = NULL;
	this->size = 0;
}

template <typename T>
Queue<T>::Queue(Queue<T> const & other) {
	init();
	copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const & other) {
	if (this != &other) {
		clean();
		copy(other);
	}

	return *this;
}

template <typename T>
Queue<T>::~Queue() {
	clean();
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return pBack == NULL;
}

template <typename T>
void Queue<T>::copy(Queue<T> const & other) {
	for (Node<T>* p = other.pFront; p != NULL; p = p->pNext) {
		enqueue(p->data);
	}
}

template <typename T>
void Queue<T>::clean() {
	while (!isEmpty()) {
		dequeue();
	}
}

template <typename T>
bool Queue<T>::enqueue(T const & elem) {
	Node<T>* p;

	try {
		p = new Node<T>(elem);
	}
	catch (...) {
		return false;
	}

	if (!isEmpty()) {
		pBack->pNext = p;
	}
	else {
		pFront = p;
	}
	pBack = p;
	size++;

	return true;
}

template <typename T>
bool Queue<T>::dequeue() {
	if (isEmpty()) {
		return false;
	}

	Node<T>* p = pFront;
	pFront = pFront->pNext;
	
	if (pFront == NULL) {
		pBack = NULL;
	}

	//T x = p->data;
	delete p;
	size--;

	return true;
}

template <typename T>
T Queue<T>::head() const {
	if (isEmpty()) {
		cerr << "Trying to dequeue from an empty queue!\n";
		return T();
	}
	return pFront->data;
}