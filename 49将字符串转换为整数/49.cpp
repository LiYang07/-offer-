//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
//要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

//输入描述:
//输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :
//如果是合法的数值表达则返回该数字，否则返回0
//示例1
//输入
//+ 2147483647
//1a33
//输出
//2147483647
//0

#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
			bool isMinus=false;
			int number = 0;
			if (str[0] <= '9'&&str[0] >= '0') 
				number = str[0] - '0';
			else if (str[0] == '-')
				isMinus = true;
			else if (str[0] != '+')
				return 0;
				
			for (int i = 1; i < str.size(); i++) {
				if (str[i] <= '9'&&str[i] >= '0')
					number = number * 10 + str[i] - '0';
				else
					return 0;
			}
			return isMinus ? -1 * number : number;
	}
};

int main(){
	Solution s;
	cout << s.StrToInt("+123");
	system("pause");
}
