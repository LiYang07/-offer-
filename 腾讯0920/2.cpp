//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//int main() {
//	int n,m=0;
//	cin >> n;
//	vector<pair<int,int>> a;
//	map<int, int> hash;
//	while (n) {
//		int cnts, t;
//		cin >> cnts >> t;
//		hash[t] = cnts;
//		m += cnts;
//		--n;
//	}
//
//	for (auto e : hash)
//		a.push_back(e);
//	m = m / 2;
//	int l = 0, r = a.size() - 1,res=0;
//	while (m) {
//		if (--a[l].second < 0) l++;
//		if (--a[r].second < 0) r--;
//		res = max(a[l].first + a[r].first, res);
//		m--;
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}