#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int dp[101][50001];

void best_alloc(vector<int> &v,int sum) {
	memset(dp, 0,101 * 50001 * sizeof(int));
	int size = v.size();
	for (int i = 1; i <=size; ++i) 
		for (int j = 1; j <= sum / 2; ++j) {
			if (j >= v[i - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + v[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	int s1 = dp[size][sum / 2], s2 = sum - dp[size][sum / 2];
	if (s1 > s2)swap(s1, s2);
	cout << s1<<" "  << s2 << endl;
}

int main() {
	int T;
	cin >> T;
	while (T) {
		int n,sum=0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		best_alloc(a,sum);
		T--;
	}
	return 0;
}