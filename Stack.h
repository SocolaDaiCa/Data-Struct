#pragma once
template<typename T>
class Stack {
public:
	T *a;
	int size;
	Stack(int maxSize) {
		a = new T[maxSize];
		reset();
	}
	void reset() { size = 0; }
	void push(T value) { a[size++] = value; }
	void top() { return a[size - 1]; }
	T pop() { return a[--size]; }
};