#include<iostream>
#include<string>
#include<stack>
#include<algorithm>


using namespace std;

int main() {
	ca
	string str;
	cin >> str;
	stack<char> stk;
	for (auto c : str) {
		if (!stk.empty()) {
			if (c - stk.top() == 1 || c - stk.top() == 2)
				stk.pop();
			else stk.push(c);
		}
		else stk.push(c);
	}
	
	if (stk.empty())
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}