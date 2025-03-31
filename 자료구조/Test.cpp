#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<int> name = { 74 , 111, 74 ,97 ,101 ,89 ,111 ,110 ,103 };
	char c;
	for (int i = 0; i < name.size(); i++) {
		c = name[i];
		cout << c;
	}
}