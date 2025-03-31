#include <iostream>
#include <string>
#include "Stack.h"

int main() {
	string str;

	cout << "�˻��ϰ� ���� ��ȣ���� �Է��ϼ���.>>";
	getline(cin, str);

	Stack stack(1000);

	int i = 0;
	int iserror = 0;
	while (str[i]) {
		switch (str[i]) {
			case '(':
				stack.push(1);
				break;

			case ')':
				if (stack.peek() == 1) {
					stack.pop();
					break;
				}
				else {
					iserror = 1;
					break;
				}

			case '{':
				stack.push(2);
				break;

			case '}':
				if (stack.peek() == 2) {
					stack.pop();
					break;
				}
				else {
					iserror = 1;
					break;
				}

			case '[':
				stack.push(3);
				break;

			case ']':
				if (stack.peek() == 3) {
					stack.pop();
					break;
				}
				else {
					iserror = 1;
					break;
				}
		}
		i++;
	}

	if (iserror)cout << "�����߰�" << endl;
	else cout << "��������" << endl;
}


