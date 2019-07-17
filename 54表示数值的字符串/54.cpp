//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100", "5e2", "-123", "3.1416"和"-1E-16"都表示数值。 
//但是"12e", "1a3.14", "1.2.3", "+-5"和"12e+4.3"都不是。

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (*string == '+' || *string == '-')
			++string;
		if (*string == '\0')
			return false;
		bool flag = true;
		scanDigits(&string);//首先跳过开始的数字
		if (*string != '\0') {
			if (*string == '.') {//为小数时
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E') {
					++string;			//判断是否为合法的幂指数
					flag = isLegalE(&string);
				}

			}
			else if (*string == 'e' || *string == 'E') {
				++string;
				flag = isLegalE(&string);
			}
			else
				flag = false;
		}
		return *string == '\0'&&flag;
	}

private:

	void scanDigits(char** string) {
		while (**string != '\0'&&**string >= '0'&&**string <= '9')
			++(*string);
		
	}
	bool isLegalE(char**string) {
		if (**string == '-' || **string == '+')
			++(*string);
		if (**string == '\0')
			return false;
		scanDigits(string);
		return (**string == '\0');
	}
};

int main() {
	Solution s;
	cout << s.isNumeric(const_cast<char*>("100"));
	system("pause");
}