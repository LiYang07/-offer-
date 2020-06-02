#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>

using namespace std;
int m, k;
long maxAns;
int pages[1010], ans[1010];

bool judge(int x) {
	int sum = 0, t = k;
	for (int i = 0; i < m; i++) {
		sum += pages[i];
		if (sum > x) {
			i--;
			sum = 0;
			t--;
		}
		if (!t) {
			if (i != m - 1) return false;
			else return true;
		}
	}
	return true;
}

void solve() {
	memset(ans, 0, sizeof(ans));
	int l, r, cur;
	l = 0; r = maxAns;
	while (l < r) {
		cur = (l + r) / 2;
		if (judge(cur))   r = cur;
		else             l = cur + 1;
	}
	int sum = 0;
	for (int i = m - 1; i >= 0; i--) {
		sum += pages[i];
		if (sum > r) {
			sum = 0;
			ans[++i] = 1;
			k--;
		}
	}
	int i = 1;
	while (k > 1) {
		for (; i < m; i++) {
			if (!ans[i]) {
				ans[i] = 1;
				k--;
				break;
			}
		}
	}
	int cursum=0,res=pages[0];
	for (int i = 0; i < m; i++) {
		if (ans[i]) {
			res = max(res, cursum);
			cursum = 0;
		}
		cursum += pages[i];
	}
	cout << res << endl;
}


int main() {
	int res;
	cin >> k;
	cin >> m;
	maxAns = 0;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < m; i++) {
		cin >> pages[i];
		maxAns += pages[i];
	}
	solve();
	return 0;

}





