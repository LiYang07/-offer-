//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//vector<int> getFriend(int m, int i, int n, vector<vector<int>> r) {
//	vector<vector<int>> dp(m, vector<int>(n, 0)); 
//	vector<int> res;
//	vector<int> t;
//	set<int> s;
//	t.resize(m);
//	for (int j = 0; j < m; j++) {
//		t[j] = j;
//	}
//
//	for (auto rv : r) {
//		if (rv[0] == i)
//		{
//			dp[rv[1]][0] = rv[2];    
//			s.insert(rv[1]);
//		}
//	}
//
//	for (int t = 1; t < n; ++t) {
//		for (auto rv : r) {
//			if (dp[rv[0]][t - 1] != 0 && rv[1] != i && s.find(rv[1]) == s.end()) {
//
//				dp[rv[1]][t] = dp[rv[0]][t - 1] + rv[2];
//				s.insert(rv[1]);
//			}
//		}
//	}
//	for (int j = 0; j < m; j++) {
//		for (int q = j + 1; q < m; ++q) {
//			if (dp[j][n - 1] < dp[q][n - 1]) {
//				int tmp = dp[j][n - 1];
//				dp[j][n - 1] = dp[q][n - 1];
//				dp[q][n - 1] = tmp;
//				tmp = t[j];
//				t[j] = t[q];
//				t[q] = tmp;
//			}
//		}
//
//	}
//	for (int j = 0; j < m; j++) {
//		if (dp[j][n - 1] > 0) {
//			res.push_back(t[j]);
//		}
//	}
//	return res;
//}
//
//int main() {
//	int T;
//	while (cin>>T) {
//		int m, i, n;
//		cin >> m >> i >> n;
//		m = 10, i = 0, n = 2;
//		int k;
//		cin >> k;
//		vector<vector<int>> r;
//		for (int i = 0; i < k; i++) {
//			r.push_back({});
//			int t;
//			for (int j = 0; j < 3; j++) {
//				cin >> t;
//				r[i].push_back(t);
//			}
//		}
//		vector<vector<int>> rFri;
//		for (auto rv : r) {
//			vector<int> tmp;
//			tmp.push_back(rv[1]);
//			tmp.push_back(rv[0]);
//			tmp.push_back(rv[2]);
//			rFri.push_back(rv);
//			rFri.push_back(tmp);
//		}
//		vector<int> res = getFriend(m, i, n, rFri);
//		if (res.size() == 0)
//			cout << "-1" << endl;
//		else {
//			for (auto v : res) {
//				cout << v << " ";
//			}
//			cout << endl;
//		}
//	}
//}