#include<iostream>
#include<vector>

using namespace std;

//在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，那么对应的输出是第一个重复的数字2。

//此题不算难,常规有两种解法，1是对数组排序，而是用hash表
//但前面时间上过于浪费，只用找任意一个，后面一个在空间上又太浪费了
//所有数都在0-n-1范围内，考虑用位图

//class Solution {
//public:
//	// Parameters:
//	//        numbers:     an array of integers
//	//        length:      the length of array numbers
//	//        duplication: (Output) the duplicated number in the array number
//	// Return value:       true if the input is valid, and there are some duplications in the array number
//	//                     otherwise false
//	bool duplicate(int numbers[], int length, int* duplication) {
//		if (length <= 1)
//			return false;
//		int lenofInt = sizeof(int)*8;
//		vector<int> bitmap(length / lenofInt + 1, 0);//位图，全部置零
//		for (int i = 0; i < length; i++) {
//			int pos = numbers[i] / lenofInt;
//			if (bitmap[pos] & (1 << (numbers[i]-1) % lenofInt))//判断是否已经置一
//			{
//				*duplication= numbers[i];
//				return true;
//
//			}		
//			else
//				bitmap[numbers[i] / lenofInt] |= (1 <<(numbers[i]-1) % lenofInt);
//		}
//		return false;
//	}
//};

class Solution {//作者的思路，直接利用下标存储已有的数据
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 1 || numbers == NULL) {
			*duplication = -1;
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i]<0 || numbers[i]>length - 1)//这里没有考虑到，错误输出的情况
			{
				return false;
			}
			while (numbers[i] != i) {
				if (numbers[numbers[i]] == numbers[i]) {
					*duplication = numbers[i];
					return true;
				}
				else
				{
					int temp = numbers[i];
					numbers[i] = numbers[temp];
					numbers[temp] = temp;
				}
			}
		}
	}
};

int main() {

	Solution s;
	int a[] = { 2, 3, 1, 3, 2, 5, 3 };
	int d = 0;
	cout << s.duplicate(a, 7, &d)<<endl;
	cout << d;
	system("pause");

}