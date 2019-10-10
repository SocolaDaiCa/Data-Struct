#pragma once
template<typename T>
class Queue {
public:
	T a[1000];
	int first, last;
	void reset() { first = last = 0; }
	void push(T value) { a[last++] = value; }
	T top() { return a[first]; }
	T pop() { return a[first++]; }
};