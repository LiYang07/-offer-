#include<iostream>
#include<vector>
#include<string>
using namespace std;

//用动态规划
//设到第i个点时的最大子向量为fi 则fi+1=fi+a[i+1]<0?a[i+1]:fi+a[i+1] 
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		vector<int> f(array.size(), 0);
		f[0] = array[0];
		int max = f[0];
		for (int i = 1; i < array.size(); i++) {
			f[i] = f[i - 1] + array[i] > array[i] ? f[i - 1] + array[i]:array[i];
			if (f[i] > max)
				max = f[i];
		}
		return max;
	}
};

int main() {
	string path("E:\\项目\\PCBData\\1\\1\\1");
	size_t p1 = path.find("PCBData");
	cout << p1 << endl;
	cout << path.substr(p1 + 7) << endl;
	Solution solu;
	cout << solu.FindGreatestSumOfSubArray({ 6,-3,-2,7,-15,1,2,2 });
	system("pause");
	return 0;
}