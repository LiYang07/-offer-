#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void transform(string& str) {//去除双引号
	 
}

int main() {
	string str;
	cin >> str;
	vector<string> subs;
	int start = 0, end = 0;
	while (end != string::npos && start<str.size()) {
		end = str.find(',', start);
		if (end != string::npos) {
			if (end - start == 0)
				subs.push_back("--");
			else {
				string sub = str.substr(start, end - start);
				if (sub.find('"') == string::npos)
					subs.push_back(sub);
				else {//特殊情况
					string temp;
					stack<int> stk;
					int i = start;
					for (; i < str.size(); i++) {
						if (str[i] == '"') {
							if (i + 1 < str.size() && str[i + 1] == '"') {//引号的情况
								temp.push_back('"');
								i += 1;
							}
							else {
								if (stk.empty()) stk.push(i);
								else stk.pop();
							}
						}
						else if (str[i] == ',') {
							if (stk.empty())
								break;
							else temp.push_back(',');
						}
						else {
							temp.push_back(str[i]);
						}
					}
					if (stk.size()) {
						cout << "ERROR" << endl;
						return -1;
					}
					end = i;
					subs.push_back(temp);
				}
			}
			start = end + 1;
		}
		else
			subs.push_back(str.substr(start, subs.size() - start));
	}
	for (auto e : subs) {
		if (1)
			cout << e << endl;
		else
			cout << e << endl;
	}
	system("pause");
	return 0;

}