#pragma once
class Tree {
public:
	long long value;
	Tree* left, * right, *childs;
	int isHold;
	int childHoldCount;
	void reset() {
		value = 0;
		left = right = childs = nullptr;
		isHold = childHoldCount = false;
	}
	void insertChild(Tree* newNode) {
		if (childs == nullptr) {
			childs = newNode;
			return;
		}
		Tree* current = childs;
		while (true)
		{
			if (current->value < value) {
				if(current->right == nullptr) {
					current->right = newNode;
					return;
				}
				current = current->right;
				continue;
			}
			if (current->left == nullptr) {
				current->left = newNode;
				return;
			}
			current = current->left;
		}
	}
	void removeChild(long long value) {
		childs = deleteNode(childs, value);
	}
	Tree *lastLeftNode(Tree *current)
	{
		while (current->left != nullptr)
			current = current->left;
		return current;
	}

	Tree* deleteNode(Tree* node, long long value) {
		if (node == nullptr) return node;
		if(node->value < value) {
			node->right = deleteNode(node->right, value);
			return node;
		}
		if (node->value > value) {
			node->right = deleteNode(node->right, value);
			return node;
		}
		if (node->left == nullptr) {
			return node->right;
		}
		if (node->right == nullptr) {
			return node->left;
		}
		Tree* lastLeft = lastLeftNode(node->right);
		node->value = lastLeft->value;
		node->childs = lastLeft->childs;
		node->right = deleteNode(node->right, node->value);
		return node;
	}
};