#pragma once
template<typename T>
class List {
public:
	template<typename T>
	class Node {
	public:
		T value;
		Node* before, * after;
		void reset() {
			before = after = NULL;
		}
	};
	Node<T> *pool;
	int nPool, size;
	Node<T>* begin, * end;
	List(int maxSize) {
		pool = new T[maxSize];
		this->reset();
	}
	Node<T>* newNode(T value) {
		pool[nPool].value = value;
		pool[nPool].before = pool[nPool].after = nullptr;
		return &pool[nPool++];
	}
	void reset() {
		size = nPool = begin = end = NULL;
	}
	void link(Node<T>* a, Node<T>* b) {
		a->after = b; b->before = a;
	}
	bool pushAfter(Node<T>* currentNode, T value) {
		Node<T>* newNode = this->newNode(value);
		size++;
		if (size == 1) return begin = end = newNode;
		if (currentNode == end) end = newNode;
		else this->link(newNode, currentNode->after);
		this->link(currentNode, newNode);
	}
	bool pushBefore(Node<T>* currentNode, Node<T>* newNode) {
		size++;
		if (size == 1) return begin = end = newNode;
		if (currentNode == begin) begin = newNode;
		else this->link(currentNode->before, newNode);
		this->link(newNode, currentNode);
	}
	void remove(Node<T>* currentNode) {
		size--;
		if (size == 0) begin = end = NULL;
		else if (currentNode == begin) begin = begin->after, begin->before = NULL;
		else if (currentNode == end) end = end->before, end->after = NULL;
		else this->link(currentNode->before, currentNode->after);
	}
};