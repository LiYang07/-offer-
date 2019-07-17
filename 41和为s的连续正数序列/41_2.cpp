//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int start = 0, end = array.size() - 1;
		int multy = 0;
		vector<int> res = { -1,-1 };
		while (start < end)
		{
			int cursum = array[start] * array[end];
			if (cursum== sum){	
				if (array[0] * array[1] > multy) {
					res[0] = array[start];
					res[1] = array[end];
					multy = array[0] * array[1];
				}
				end--;
			}
			else if (cursum > sum) {
				end--;
			}
			else
				start++;
		}
		return res[0] == -1 ? vector<int>({}):res;
	
	}
};