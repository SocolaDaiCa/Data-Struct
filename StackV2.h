#pragma once
template<typename T>
class Stack {
public:
	T a[1000];
	int size;
	void reset() {
		size = 0;
	}
	T top() { return a[size]; }
	void push(T value) { a[++size] = value; }
	T pop() { return a[size--]; }
};