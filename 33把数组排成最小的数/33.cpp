//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{ 3，32，321 }，
//则打印出这三个数字能排成的最小数字为321323。
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//此题需要定义自己的排序规则，将整数转换为字符串后
//按此规则给字符串进行排序

bool myCmp(const string&a, const string&b) {
	string ab = a + b, ba = b + a;
	return ab < ba ? true :false;
}

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> str_numbers;
		for (auto i : numbers)
			str_numbers.push_back(to_string(i));
		sort(str_numbers.begin(), str_numbers.end(), myCmp);
		string res;
		for (auto s : str_numbers)
			res += s;
		return res;
	}
};

int main() {
	vector<int> numbers = { 3,32,321 };
	Solution s;
	cout << s.PrintMinNumber(numbers);
	system("pause");
	/*vector<string> slist = { "78","45","6","62" }, slist2 = { "3","32","321" };
	sort(slist.begin(), slist.end());
	sort(slist2.begin(), slist2.end());
	for (auto s : slist)
		cout << s << " ";
	cout << endl;
	for (auto s : slist2)
		cout << s <<" ";
	cout << endl;
	system("pause");*/

}


