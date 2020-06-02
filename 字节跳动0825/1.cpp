//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 100009;
//int f[N];
//
//
//
//int find(int x) {
//	return x == f[x] ? x : f[x] = find(f[x]);
//}
//
//int main() {
//	int n, t;
//	cin >> n;
//	vector<vector<int> > friends;
//	for (int i = 0; i < n; i++) {
//		friends.push_back({});
//		for (int j = 0; j < n; j++){
//			cin >> t;
//		friends[i].push_back(t);
//		}
//	}
//	for (int i = 0; i < n; i++)
//		f[i] = i;
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; j++)
//			if (friends[i][j] >= 3) {
//				int fx = find(i), fy = find(j);
//				if (fx != fy)
//					f[fx] = fy;
//			}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//		if (i == find(i))
//			ans++;
//	cout << ans << endl;
//}
