#pragma once
#define MAX_LIST_POOL_SIZE 1000
class List {
public:
	static int values[MAX_LIST_POOL_SIZE];
	static int befores[MAX_LIST_POOL_SIZE];
	static int afters[MAX_LIST_POOL_SIZE];
	static int nPool;
	int size, begin, end;
	void reset() {
		size = begin = end = 0;
		befores[0] = afters[0] = 0;
	}

	static int newNode(int value) {
		++nPool;
		values[nPool] = value;
		befores[nPool] = afters[nPool] = 0;
		return nPool;
	}

	void link(int a, int b) {
		if(a) afters[a] = b;
		if(b) befores[b] = a;
	}

	void pushAfter(int current, int value) {
		size++;
		int newNode = this->newNode(value);
		this->link(current, newNode);
		this->link(newNode, afters[current]);
		if (befores[newNode]) begin = newNode;
		if (afters[newNode]) end = newNode;
	}
	void pushBefore(int current, int value) {
		size++;
		int newNode = this->newNode(value);
		this->link(befores[current], newNode);
		this->link(newNode, current);
		if (befores[newNode]) begin = newNode;
		if (afters[newNode]) end = newNode;
	}
	void remove(int current) {
		size--;
		this->link(befores[current], afters[current]);
		if (current == begin) end = afters[current];
		if (current == end) end = befores[current];
	}
};