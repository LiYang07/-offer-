#include<iostream>
#include<string>
#include<map>

using namespace std;

// ±º‰∏¥‘”∂»On^2
//class Solution {
//public:
//	int FirstNotRepeatingChar(string str) {
//		for (int i = 0; i < str.size(); i++) {
//			if (str.find_first_of(str[i], str.find_first_of(str[i]) + 1) == string::npos)
//				return i;
//		}
//		return -1;
//
//	}
//};

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
			int count[256] = { 0 };
			for (auto c : str)
				count[int(c)]++;
			for (int i=0;i<str.size();i++)
				if (count[str[i]] == 1)
					return i;
			return -1;
	}
};

int main(){
	int a[10] = {0};
	cout << a[1];
	Solution s;
	cout << s.FirstNotRepeatingChar("google") << endl;
	system("pause");
}