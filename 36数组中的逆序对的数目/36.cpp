//题目描述
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组, 求出这个数组中的逆序对的总数P。
//并将P对1000000007取模的结果输出。 即输出P % 1000000007
//输入描述:
//题目保证输入的数组中没有的相同的数字
//
//数据范围：
//
//对于 % 50的数据, size <= 10 ^ 4
//
//对于 % 75的数据, size <= 10 ^ 5
//
//对于 % 100的数据, size <= 2 * 10 ^ 5
//
//示例1
//输入
//1, 2, 3, 4, 5, 6, 7, 0
//输出
//7

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() <= 1){		
		cout << 0;
		return 0;
		}
		count = 0;
		vector<int> copy(data.begin(), data.end());
		InverseCore(data, copy, 0, data.size() - 1);
		return count%1000000007;
	}
private:
	void InverseCore(vector<int>&data, vector<int>&copy, int l,int r) {
		if (l == r)
		{
			copy[l] = data[l];
			return;
		}
		int len = (r - l) / 2;
		InverseCore(copy, data, l, l + len);//交换实参顺序，实际上是在修改copy中的数组，
		InverseCore(copy, data, l + len + 1, r);
		int i = l + len;
		int j = r;
		int indexCopy = r;
		while (i >= l && j >= l + len + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				count += j - (l + len);
			}
			else {
				copy[indexCopy--] = data[j--];
			}
		}
		for (; i >= l; --i)
			copy[indexCopy--] = data[i];
		for (; j >= l + len + 1; --j)
			copy[indexCopy--] = data[j];
	}
	long long count;
};

int main() {
	Solution s;
	cout<<s.InversePairs({7,5,6,4 });
	system("pause");
}