//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#include<iostream>
#include<vector>
using namespace std;
int threeMin(int a, int b, int c) {
		
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
//参考作者解法
//自己写的未考虑到输入为0的情况
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		int *pUglyNumber = new int[index];
		pUglyNumber[0] = 1;
		int *pMultiply2 = pUglyNumber;
		int *pMultiply3 = pUglyNumber;
		int *pMultiply5 = pUglyNumber;
		int nextUgly = 1;
		while (nextUgly < index) {
			pUglyNumber[nextUgly] = threeMin(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
			while (*pMultiply2 * 2 <= pUglyNumber[nextUgly])
				++pMultiply2;
			while (*pMultiply3 * 3 <= pUglyNumber[nextUgly])
				++pMultiply3;
			while (*pMultiply5 * 5 <= pUglyNumber[nextUgly])
				++pMultiply5;
			++nextUgly;
		}
		int ugly = pUglyNumber[--nextUgly];
		delete[] pUglyNumber;
		return ugly;
	}
};

int main() {
	Solution s;
	cout<<s.GetUglyNumber_Solution(8)<<endl;
	cout << threeMin(9, 5, 1) << endl;
	system("pause");
}