#pragma once
template<typename T>
class Queue {
public:
	T *a;
	int first, last;
	Queue(int maxSize) {
		*a = new T[maxSize];
	}
	void reset() { first = 0; last = 0; }
	void push(T value) { a[last++] = value; }
	int size() { return last - first }
	T top() { return a[fisrt]; }
	T pop() { return a[first++]; }
};