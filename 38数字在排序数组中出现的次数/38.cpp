#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		if (data.empty())
//			return 0;
//		int firstPos=GetfirstPos(data, 0, data.size(), k);
//		if (firstPos == -1)
//			return 0;
//		cout << GetLastPos(data, 0, data.size(), k) << endl;
//	}
//private:
//	int GetfirstPos(vector<int>&data,int start,int end,int k) {
//		if (start > end)
//			return -1;
//		int middle = (start + end) / 2;
//		if (data[middle] == k) {
//			if (middle == 0 || data[middle - 1] != k)
//			{
//				return middle;
//			}
//				
//			else
//				end = middle - 1;
//		}
//		else if (data[middle] > k)
//			end = middle - 1;
//		else
//			start = middle+1;
//		return GetfirstPos(data, start, end, k);
//	}
//	int GetLastPos(vector<int>&data, int start, int end, int k) {
//		if (start > end)
//			return -1;
//		int middle = (start + end) / 2;
//		if (data[middle] == k) {
//			if (middle == data.size() - 1 || data[middle + 1] != k)
//			{
//				return middle;
//			}
//			else
//				start = middle + 1;
//		}
//		else if (data[middle] > k)
//			end = middle - 1;
//		else
//			start = middle + 1;
//		return GetLastPos(data, start, end, k);
//	
//	}
//};

//stl的equal_range也可以用于此，内部也是用二分查找实现
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		auto ite = equal_range(data.begin(), data.end(), k);
		return ite.second - ite.first;
	}

};

int main() {
	Solution s;
	cout << s.GetNumberOfK({ 1,2,3,3,3,3,4,5 }, 3) << endl;
	system("pause");

}