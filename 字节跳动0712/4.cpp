#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<pair<int, int>> nums;

bool mycmp1(const pair<int, int> &A, const pair<int, int> &B) {//优先以第一个数排序
	return A.first < B.first || (A.first == B.first&&B.second < A.second);
}
bool mycmp2(const pair<int, int> &A, const pair<int, int> &B) {//优先以第二个数排序
	return A.second < B.second || (A.second == B.second&&B.first < A.first);
}

//int main() {
//	std::ios::sync_with_stdio(false);
//	int n;
//	cin >> n;
//	int a, b;
//	map<int, int> small = { {0,0} };
//	map<int, int>  big = { {0,0} };
//	cin >> a >> b;
//	if (a > b)
//		swap(a, b);
//	small[a]++;
//	big[b]++;
//	nums.push_back(pair<int,int>(a,b));
//	bool flag = false;
//	int maxa = a;
//	int maxb = b;
//	for (int i = 1; i < n; i++) {
//		cin >> a >> b;
//		if (a > b) swap(a, b);
//		if ((++small[a] == 1) && (++big[b] == 1)) {//都是第一次出现
//			flag = true;
//		}
//		nums.push_back(pair<int, int>(a, b));
//		if (small[a] > small[maxa])maxa = a;
//		if (big[b] > big[maxb])maxb = b;
//	}
//	if (flag)
//		cout << "No";
//	else {
//
//		if (maxb > maxa) {//找到small中第二项非等于maxb的最多的数。
//			sort(nums.begin(), nums.end(), mycmp2);
//			int i = nums.size() - 1;
//			while (nums[i].second == maxb)i--;
//			cout << nums[i].first << " " << maxb;
//		}
//		else
//		{
//			sort(nums.begin(), nums.end(), mycmp1);
//			int i = nums.size() - 1;
//			while (nums[i].first == maxa)i--;
//			cout << maxa << " " << nums[i].second;
//		}
//	}
//		return 0;
//
//}
//	
