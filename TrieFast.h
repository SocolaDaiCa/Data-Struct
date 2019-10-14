#pragma once
int _2_pow[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432 };
class Trie {
public:
	class Node {
	public:
		int value;
		int check;
		Node* childs[26];
		void reset() {
			value = check = 0;
		};
	};
	static Node pool[10000], root;
	static char values[10000][21];
	static int nPool;
	int index;
	void reset() {
		root.reset();
		index = 0;
	};
	static void strcopy(char* from, char* to) {
		int i = 0;
		while (from[i]) to[i] = from[i++];
		to[i] = '\0';
	}
	Node* newNode() {
		pool[nPool].reset();
		return &pool[nPool++];
	}
	int add(char* s) {
		int key;
		Node* node = &root;
		for (int i = 0; s[i]; i++) {
			key = s[i] - 97;
			if ((node->check & _2_pow[key]) == 0) {
				node->childs[key] = newNode();
			}
			node = node->childs[key];
		}
		if (node->value == 0) {
			node->value = ++index;
			strcopy(s, values[index]);
		}
		return node->value;
	}
};