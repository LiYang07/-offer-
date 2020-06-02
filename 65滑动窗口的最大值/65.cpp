#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<numeric>
using namespace std;


class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		if (size<1||size>num.size())
			return {};
		vector<int> res;
		deque<int> index;
		for (int i = 0; i < size; i++) {
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		
		for (int i = size; i < num.size(); i++) {
			res.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= i - size)//已经属于当前队列
				index.pop_front();
			index.push_back(i);
		}
		res.push_back(num[index.front()]);
		return res;
	}
};

int main() {
	Solution s;
	vector<int> res = s.maxInWindows({ 2,3,4,2,6,2,5,1 },3);
	for (auto i : res)
		cout << i << endl;
	system("pause");
}