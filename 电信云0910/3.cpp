#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	vector<int> a;
	int t;
	char c;
	while (cin >> c) {
		cin >> t;
		a.push_back(t);
	}
	int n = a.size(), ans;
	vector<int> f(n);
	f[0] = a[0];
	ans = f[0];
	for (int i = 1; i < n; i++) {
		f[i] = max(f[i - 1] + a[i], a[i]);
		ans = max(ans, f[i]);
	}
	
}