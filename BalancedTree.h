#pragma once
class BalancedTree {
	void swap(int& x, int &y) {
		x ^= y ^= x ^= y;
	}
	int a[1000];
	int size = 0;
	void add(int value) {
		a[++size] = value;
		int index = size, left, right, parrent;
		bool isLeft, isRight;
		while (true) {
			parrent = index >> 1;
			left = index << 1;
			right = (index << 1) + 1;
			isLeft = ((index >> 1) << 1) == index;
			isRight = ((index >> 1) << 1) == index - 1;


			if (parrent && isLeft && a[index] > a[parrent]) // index la con trai va lon hon bo
				swap(a[index], a[parrent]), index >>= 1, continue;
			else if (parrent && isRight && a[index] < a[parrent]) // la con phai va nho hon bo
				swap(a[index], a[index >> 1]), index >>= 1;
			else if (left <= size && a[index] < a[left]) // la bo va nho hon con trai
				swap(a[index], a[left]), index = left;
			else if (right <= size && a[index] > a[right]) // la bo va lon hon con phai
				swap(a[index], a[right]);
			else
				break;
		}
	}
};