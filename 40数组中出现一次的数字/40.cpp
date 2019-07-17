//数组中只有两个数字只出现了一次，其他数字都出现了两次
//要求时间复杂度O(n)，空间复杂度O(1)
#include<iostream>
#include<vector>

using namespace std;

//异或算法，从头到尾异或每一个数
//按异或结果第一位为1的位是否为0，将数组分成两部分，再分别异或，最后的结果即是只出现一次的数
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int test = 0;
		for (auto i : data)
			test ^= i;
		int indexBit = 0;
		while (((test & 1) == 0) && (indexBit <= 8 * sizeof(int))){
			test=test >> 1;
			indexBit++;
		}
		int testBit = 1 << indexBit;
		*num1 = 0, *num2 = 0;
		for (auto i : data) {
			if (i&testBit)
				*num1 ^= i;
			else
				*num2 ^= i;
		
		}
	}
};

int main() {
	int num1, num2;
	Solution s;
	s.FindNumsAppearOnce({ 2,4,3,6,3,2,5,5 }, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	system("pause");
}
