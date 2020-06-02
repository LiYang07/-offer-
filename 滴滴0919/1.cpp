#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;

int a[N];
long sums[N];

int main() {
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sums[i] = sums[i - 1] + a[i];
	}
	long ans = sums[m];
	for (int i = 0; i <= n - m ; i++) {
		for (int j = i + m; j <= n; j++ )
			ans = min(ans, sums[j] - sums[i]);
	}
	cout << ans << endl;
	return 0;
}