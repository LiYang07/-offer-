//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
#include<iostream>

using namespace std;


class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		//if the next character in pattern is not '*'
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		//if the next character is '*'
		else
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str, pattern + 2) || match(str + 1, pattern);
			else
				return match(str, pattern + 2);
		}
	}
};
//class Solution {
//public:
//	bool match(char* str, char* pattern)
//	{
//		return matchCore(str, pattern);
//	}
//private:
//	//作者的这种写法同样也太冗余了，复杂度过高，牛课上不能通过
//	bool matchCore(char*str, char* pattern) {//此题关键在于模式传上出现*时的状态转移问题
//		if (*str == '\0'&&*pattern == '\0')
//			return true;
//		if (*str != '\0'&&*pattern == '\0')
//			return false;
//
//		if (*(pattern + 1) == '*') {
//			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
//				return matchCore(str + 1, pattern + 2) || //只出现一次的情况
//				matchCore(str + 1, pattern) || //字符中重复的情况
//				matchCore(str, pattern);//忽略当前模式
//			else
//				return matchCore(str, pattern + 2);//忽略当前模式
//
//		}
//		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
//			return matchCore(str + 1, pattern + 1);
//		return false;
//	}
//
//	//自己写的考虑仍然不周全,可能在部分测试用例上遇到死循环
//	/*	if (*str == *pattern)
//			return matchCore(str + 1, pattern + 1);
//		else {
//			if (*pattern == '.')
//				return matchCore(str + 1, pattern + 1);
//			if (*(pattern+1)!='\0'&&*(pattern+1)=='*')
//				return matchCore(str, pattern + 2);
//			if (*pattern == '*')
//				return matchCore(str + 1, pattern - 1);
//		
//		}
//		return false;
//	}*/
//};

int main() {
	Solution s;
	char* str = const_cast<char*>("aaa");
	char* pattern = const_cast<char*>("a..*");
	cout << s.match(str,pattern) << endl;
	system("pause");
}