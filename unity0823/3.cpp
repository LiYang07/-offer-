//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//int main() {
//	int n,t;
//	cin >> n;
//	vector<int> a(n,0);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	map<int, int> hash;
//	hash[a[n - 1]]++;
//	vector<int > res(n, 0);
//	for (int i = n - 2; i >= 0; i--) {
//		auto it = hash.begin();
//		while (it != hash.end() && (*it).first < a[i]) {
//			res[i] += (*it).second;
//			it++;
//		}
//		hash[a[i]]++;
//	}
//	for (auto i : res)
//		cout << i <<" ";
//	return 0;
//}