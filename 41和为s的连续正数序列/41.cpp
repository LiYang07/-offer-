#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		int mid = (sum + 1) / 2;//ËÑË÷ÉÏÏÞ
		int small = 1, big = 2;
		int curSum = small + big;
		vector<vector<int>> res;
		while (small < mid) {
			if (curSum == sum) {
				res.push_back(getSequenseVec(small, big));
				big++;
				curSum += big;
			}
			else if (curSum < sum) {
				big++;
				curSum += big;
			}
			else
			{
				curSum -= small;
				small++;
			}
		}
		return res;
	}
private:
	vector<int> getSequenseVec(int small, int big) {
		vector<int> out;
		while (small <= big)out.push_back(small++);
		return out;
	}
};

int main(){
	Solution s;
	vector<vector<int>> res = s.FindContinuousSequence(100);
	system("pause");
}