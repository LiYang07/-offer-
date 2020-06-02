//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//
//int main() {
//	int n,t;
//	cin >> n;
//	//二分解法
//	vector<int> a;
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		a.push_back(t);
//	}
//	vector<int> ast(n + 1, 0);//辅助数组
//	ast[1] = a[0];
//	int maxlen = 1;
//	for (int i = 1; i < n; i++) {
//		int left = 1;
//		int right = maxlen;
//		while (left <= right) {//二分查找
//			int mid = (left + right) / 2;
//			if (ast[mid] <= a[i])
//				left = mid + 1;
//			else
//				right = mid - 1;
//		}
//		ast[left] = a[i];//维护ast数组
//		if (left > maxlen)//left值是nums[i]的子序列长度
//			maxlen = left;
//	}
//	cout << maxlen << endl;
//	return 0;
//}