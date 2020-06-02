//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//bool mycmp(const pair<int, int> &A, const pair<int, int> &B) { //排在前面的a尽量大,b尽量小
//	if (A.first > B.first) {
//		if (A.second <= B.second)
//			return true;
//		else
//			return A.first >= A.second;
//	}
//	else if (A.first == B.first) {
//		return A.second < B.second;
//	}
//	else { //系数a比较大
//		if (A.second >= B.second)
//			return false;
//		else
//			return A.second > A.first;
//	}
//
//}
//
//int main() {
//	int n,a,b;
//	cin >> n;
//	vector<pair<int, int>> sats;//存储满意度系数
//	for (int i = 0; i < n; i++) {
//		cin >> a >> b;
//		sats.push_back( make_pair(a,b) );
//	}
//	sort(sats.begin(), sats.end(), mycmp);
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//		sum += sats[i - 1].first*(i - 1) + sats[i - 1].second*(n - i);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}