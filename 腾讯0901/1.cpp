//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int main() {
//	int n, m,t;
//	cin >> n >> m;
//	int boxOdds = 0, boxEvens = 0;//盒子上奇数、偶数的个数
//	int keyOdds = 0, keyEvens = 0;//钥匙上奇数、偶数的个数
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		if (t & 1) ++boxOdds;
//		else ++boxEvens;
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> t;
//		if (t & 1) ++keyOdds;
//		else ++keyEvens;
//	}
//	int res = min(boxOdds, keyEvens) + min(boxEvens, keyOdds);
//	cout << res << endl;
//	return 0;
//}