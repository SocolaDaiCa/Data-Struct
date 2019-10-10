#pragma once
template<typename T>
class Tree {
public:
	class Node {
	public:
		int value;
		int count;
		Node* left, * right;
	};
	Node pool[10000];
	Node* root;
	int size, nPool;
	Tree() { reset(); }
	void reset() {
		size = nPool = 0;
		root = NULL;
	}
	Node* newNode(int value) {
		pool[nPool].value = value;
		pool[nPool].count = 1;
		pool[nPool].left = pool[nPool].right = nullptr;
		return pool[nPool++];
	}
	void add(int value) {
		this->root = _insert(this->root, value);
	}
	Node* add(Node* node, int value) {
		if (node) return newNode(value);
		if (node->value < value) node->right = add(node->right, value);
		else if (node->value > value) node->left = add(node->left, value);
		else (node->value == node) node.count++;
		return node;
	}
	Node* find(int value) {
		return find(root, value);
	}
	Node* find(Node *node, int value) {
		if (!node || node->value == value) return node;
		if (node->value < value) return find(node->right, value);
		return find(node->left, value);
	}

};