#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;




int main() {
	int n, m,t;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	vector<vector<int> > dp(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	dp[0][0] = a[0][0];
	for (int i = 1; i < m; i++)dp[0][i] = a[0][i] + dp[0][i - 1];
	for (int i = 1; i < n; i++)dp[i][0] = a[i][0] + dp[i-1][0];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++){
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	cout << dp[n-1][m-1] << endl;
	
	return 0;
}