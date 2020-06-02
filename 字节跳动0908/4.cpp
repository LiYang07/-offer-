#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> ans;
void dfs(const string &s, int index, string &res) {
	if (index == s.size())
	{
		ans.push_back(res);
		return;
	}
	if (s[index] != '0') {
		res.push_back('A' + (s[index] - '1'));
		dfs(s, index + 1, res);
		res.pop_back();
	}
	else
		dfs(s, index + 1, res);
	if (index < s.size() - 1) {
		int t = (s[index] - '0') * 10 + s[index + 1] - '0';
		if (t >= 10 && t <= 26) {
			res.push_back('A' + t - 1);
			dfs(s, index + 2, res);
			res.pop_back();
		}
	}
}


int main() {
	string s;
	cin >> s;
	if(s.size()<1 || s[0]<'1' || s[0]> '9'){
		cout << "";
		return 0;
	}
	string res;
	dfs(s, 0, res);
	for (auto e : ans)
		cout << e << endl;
	return 0;
}