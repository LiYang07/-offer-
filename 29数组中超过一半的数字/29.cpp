//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
#include<iostream>
#include<vector>

using namespace std;
//根据作者提示，此题共有两种解法
//第一种用parttion，找出中位数，然后再统计中位数的个数
//第二种采用直接比较统计数字多少的方式，即用两个数，一个存放数字，另外一个存放该数字比其他数字多的个数
//若在遍历时遇到不同的数字，将次数减1，当该次数小于0是更新数字值，并将次数置为1
class Solution {
public:
	static int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int curNum = numbers[0], moreTimes = 1;
		for (int i = 1; i < numbers.size(); i++) {
			if (curNum == numbers[i])
				moreTimes++;
			else {
				if (--moreTimes < 0) {
					curNum = numbers[i];
					moreTimes = 0;
				}
			}
			return moreTimes >= 1 ? curNum : 0;
		}
	}
};

int main() {
	vector<int> numbers = { 1,2,3,2,2,2,5,4,2 };
	cout << Solution::MoreThanHalfNum_Solution(numbers) << endl;

}