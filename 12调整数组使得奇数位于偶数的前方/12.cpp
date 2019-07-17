//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {//若要相对位置不变，最便捷的是用另外一个数组来处理
		vector<int> array_help(array.size(), 0);
		int len = array.size(), eve_count = 0;
		for (int i = 0; i < len; i++) {
			if (array[i] % 2)
				array_help[eve_count++] = array[i];
		}
		int odd_count = len - eve_count;
		while (odd_count&&len) {
			if (!(array[--len] % 2))
				array_help[eve_count - 1 + odd_count--] = array[len];
		}
		copy(array_help.begin(), array_help.end(), array.begin());

	}
};