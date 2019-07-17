//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent <= 2)
			return pow(base, exponent);
		if (exponent % 2)
			return base * pow(Power(base, (exponent - 1) / 2), 2);
		else
			return pow(Power(base, exponent / 2), 2);
	}
};