//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S = ”abcXYZdef”, 
//要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
#include<iostream>
#include<string>

using namespace std;
//实际上就是字符串旋转的问题
//stl中的rotate有实现
//可以用逐段交换操作，也可以用三次反转操作来实现
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty())//要考虑除0的情况
			return str;
		int mid = n % str.size();
		//string copy = str;
		_reverse(str, 0, mid - 1);
		_reverse(str, mid, str.size() - 1);
		_reverse(str, 0, str.size() - 1);
		return str;
	}
private:
	void _reverse(string&s, int start, int end) {
		while (start < end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
};
//int main() {
//	Solution s;
//	cout << s.LeftRotateString("abcdefghi", 3);
//	system("pause");
//
//}