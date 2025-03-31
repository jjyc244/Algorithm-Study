#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	string s;
	double AtoZ[26];
	stack<double> Stack[100];

	cin >> N;
	cin.ignore();
	getline(cin, s);
	for (int i = 0; i < N; i++) {
		cin >> AtoZ[i];
	}

	int i = 0;
	while (s[i]) {
		if (s[i] == '-' or s[i] == '+' or s[i] == '*' or s[i] == '/') {
			switch (s[i]) {
			case '-':
				int a = Stack.pop();
				int b = Stack.pop();
				Stack.push(a - b);
				break;

			case '+':
				int a = Stack.pop();
				int b = Stack.pop();
				Stack.push(a + b);
				break;

			case '*':
				int a = Stack.pop();
				int b = Stack.pop();
				Stack.push(a * b);
				break;

			case '/':
				int a = Stack.pop();
				int b = Stack.pop();
				Stack.push(a / b);
				break;

			}
		}
		else {
			Stack.push(AtoZ[s[i] - 'A']);
		}
		i++;
	}
	cout << Stack->pop();

}