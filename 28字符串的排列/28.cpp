#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.size())
			PermutationCore(str, 0);
		sort(_res.begin(), _res.end());//要按字符序输出
		return _res;
	}
private:
	void PermutationCore(string& str, int pos) {
		if (pos == str.size() && find(_res.begin(), _res.end(), str) == _res.end())//增加一步判定重复操作，会增加复杂度
			_res.push_back(str);
		else {
			for (int i = pos; i < str.size(); i++) {
				swap(str[pos], str[i]);
				PermutationCore(str, pos + 1);
				swap(str[pos], str[i]);//递归返回会后需要交换回来，避免重复
			}
		}
	}
	vector<string> _res;
};


int main() {
	Solution s;
	vector<string> res=s.Permutation("AAD");
	string a="abc";
	for (auto elem : res)
		cout<<elem<<" ";
	system("pause");
	return 0;
}