#include<algorithm>
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Solution {//维护一个大根堆，一个小根堆，并保持两者的size不超过1
public:
	void Insert(int num)
	{
		if (((min.size() + max.size()) & 1) == 0) {//偶数，即两者size一样时,保证向小顶堆中插入
			if (max.size() > 0 && num < max[0]) {//本来应该压入max中
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else {//奇数，min中至少有一个,
			if (min.size() > 0 && num > min[0]) {//本来该压入min中
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = min.size() + max.size();
		assert(size != 0);
		if ((size & 1) == 1)
			return double(min[0]);
		else
			return double((min[0] + max[0]) / 2.0);
	}
private:
	vector<int>  min;
	vector<int>  max;

};

int main(){
	vector<int> v = { 6,8,4,10,9,13,3,1 };
	Solution s;
	for (auto i : v)
		s.Insert(i);
	system("pause");
}