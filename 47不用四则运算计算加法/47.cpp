//写一个函数，求两个整数之和，要求在函数体内不得使用 + 、 - 、 * 、 / 四则运算符号。

#include<iostream>

using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		do {
			sum = num1 ^ num2;//没有计算进位的加法
			carry = (num1&num2) << 1; //计算进位
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return sum;

	}
};