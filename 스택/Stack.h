#ifndef STACK_h
#define STACK_h

#include <iostream>
using namespace std;

class Stack {
	int* arr;
	int top;
	int size;
public:
	Stack(int size) {
		this->size = size;
		this->arr = new int[size];
		this->top = -1;
	}
	~Stack() {
		delete[] arr;
	}
	bool isfull() {
		return top == size - 1;
	}
	bool empty() {
		return top == -1;
	}
	void push(int n) {
		if (isfull()) {
			cout << "�迭�� ũ�Ⱑ ������� �ʽ��ϴ�" << endl;
			return;
		}
		this->arr[++top] = n;
	}
	int pop() {
		if (empty()) {
			cout << "������ ����ֽ��ϴ�" << endl;
			return -1;
		}
		return this->arr[top--];
	}
	int peek() {
		if (empty()) {
			cout << "������ ����ֽ��ϴ�" << endl;
			return -1;
		}
		return this->arr[top];
	}
};

#endif