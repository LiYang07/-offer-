#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N = 501;

int G[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		G[a][b] = 1;
	}
	if (n & 0)cout << n << endl;
	else cout << n - 1 << endl;
	return 0;
}