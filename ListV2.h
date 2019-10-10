#pragma once
template<typename T>
class List {
public:
	class Node {
		T value;
		int before, after;
	};
	Node pool[10000];
	int nPool, size;
	int begin, end;
	void reset() {
		nPool = size = begin = end = 0;
	}
	int newNode(T value) {
		nPool++;
		node[nPool].value = value;
		node[nPool].left = node[nPool].right = 0;
	}
	void pushAfter(int node, T value) {
		int newNode = newNode(value);
		size++;
		if (size == 1) return begin = end = newNode;
		if (node == end) {
			end = newNode;
		}
		else {
			
		}
		a[node].after = newNode;
		a[newNode].before = 
	}
};