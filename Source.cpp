#include <stdio.h>
#include "TrieFast.h"
//#include <iostream>
//using namespace std;
//#include "Stack.h"
//#include "Queue.h"
//#include "List.h"


//
//template<typename T>
//class Trie {
//public:
//	#define CHILDS_SIZE 10
//	template<typename T>
//	class Node {
//	public:
//		T value;
//		Node<T>* childs;
//	};
//	Node<T> pool[1000][100], dom;
//	int nPool;
//	void reset() {
//		nPool = dom.childs = NULL;
//	}
//	Node<T> *newChilds(T value) {
//		for (int i = 0; i < CHILDS_SIZE; i++) pool[nPool][i].childs = NULL;
//		return &pool[nPool++];
//	}
//};
//template<typename V>
//class Map {
//	rows[10000]
//	void set(int key, V value) {
//
//	}
//	T get(int key) {
//		return NULL;
//	}
//
//};

//class ListV1 {
//public:
//	class Node {
//	public:
//		int value;
//		Node* before, * after;
//	};
//	Node pool[1001], *begin, *end;
//	int nPool, size;
//	void reset() {
//		nPool = size = 0;
//		begin = end = 0;
//	}
//	Node* newNode(int value) {
//		Node* node = &pool[nPool++];
//		node->before = node->after = nullptr;
//		node->value = value;
//		return node;
//	}
//	void link(Node* a, Node* b) {
//		a->after = b;
//		b->before = a;
//	}
//	bool pushAfter(Node* current, int value) {
//		Node* newNode = this->newNode(value);
//		size++;
//		if (size == 1) return begin = end = newNode;
//		if (current == end) end = newNode;
//		else link(newNode, current->after);
//		link(current, newNode);
//	}
//	bool pushBefore(Node* current, int value) {
//		Node* newNode = this->newNode(value);
//		size++;
//		if (size == 1) return begin = end = newNode;
//		if (current == begin) begin = newNode;
//		else link(current->before, newNode);
//		link(newNode, current);
//	}
//	bool remove(Node* current) {
//		if (size == 0) return;
//		size--;
//		if (size == 0) begin = end = nullptr;
//		else if (current == begin) {
//			begin = begin->after;
//			begin->before = nullptr;
//		}
//		else if (current == end) {
//			end = end->before;
//			end->after = nullptr;
//		} else link(current->before, current->after);
//	}
//};
//
//class ListV2 {
//public:
//	class Node {
//	public:
//		int value, before, after;
//	};
//	Node pool[1001];
//	int nPool, size, begin, end;
//	void reset() {
//		pool[0].before = pool[0].after = nPool = size = begin = end = 0;
//		 
//	}
//	int newNode(int value) {
//		pool[++nPool].value = value;
//		pool[nPool].before = pool[nPool].after = 0;
//		return nPool;
//	}
//	void link(int a, int b) {
//		pool[a].after = b;
//		pool[b].before = a;
//	}
//	void pushAfter(int current, int value) {
//		size++;
//		int newNode = this->newNode(value);
//		link(newNode, pool[current].after);
//		link(current, newNode);
//		if (current == end) end = newNode;
//	}
//	void pushBefore(int current, int value) {
//		size++;
//		int newNode = this->newNode(value);
//		link(pool[current].before, newNode);
//		link(newNode, current);
//		if (current == begin) begin == newNode;
//	}
//
//};


//List<int> list;

int main() {
	Trie trie;
	/*int* a = null;
	int* b = nullptr;
	printf("%d", a);*/
	/*list.pushAfter(list.begin, 5);
	cout << "list size: " << list.size << endl;*/
	//cout << "ahihi";
}