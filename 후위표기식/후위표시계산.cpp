#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int N;
	string s;
	double AtoZ[26];
	stack<double> Stack;

	cin >> N;
	cin.ignore();
	getline(cin, s);
	for (int i = 0; i < N; i++) {
		cin >> AtoZ[i];
	}

	int i = 0;
	double a;
	double b;
	while (s[i]) {
		if (s[i] == '-' or s[i] == '+' or s[i] == '*' or s[i] == '/') {
			switch (s[i]) {
			case '-':
				b = Stack.top();
				Stack.pop();
				a = Stack.top();
				Stack.pop();
				Stack.push(a - b);
				break;

			case '+':
				a = Stack.top();
				Stack.pop();
				b = Stack.top();
				Stack.pop();
				Stack.push(a + b);
				break;

			case '*':
				a = Stack.top();
				Stack.pop();
				b = Stack.top();
				Stack.pop();
				Stack.push(a * b);
				break;

			case '/':
				b = Stack.top();
				Stack.pop();
				a = Stack.top();
				Stack.pop();
				Stack.push(a / b);
				break;

			}
		}
		else {
			Stack.push(AtoZ[s[i] - 'A']);
		}
		i++;
	}
	cout << fixed << setprecision(2) << Stack.top() << endl;

}