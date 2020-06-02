#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main() {
	string s;
	cin >> s;
	stack<char> stk;
	for (auto c : s) {
		if (c == '(')
			stk.push(c);
		else if (c == ')') {
			if (!stk.empty())
				stk.pop(); 
			else {
				cout << "false" << endl;
				return 0;
			}
		}
		else {
			cout << "false" << endl;
			return 0;
		}
	}
	if (stk.empty())
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}