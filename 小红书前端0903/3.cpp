#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool mycmp(const vector<int> &a, const vector<int> &b) {
	int maxa = max(a[0], a[1]), maxb = max(b[0], b[1]);
	int mina = min(a[0], a[1]), minb = min(b[0], b[1]);
	if (maxa < maxb)
		return true;
	else if(maxa == maxb) {
		if (mina < minb)
			return true;
		else
			return false;
	}
	else return false;
}
int main() {
	int n;
	cin >> n;
	if (n <= 1) {
		cout << n<<endl;
		return 0;
	}
	vector<vector<int> > a(n, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	sort(a.begin(), a.end(), mycmp);
	int i = 0;
	int curx = a[i][0], curh = a[i][1];
	int res = 1;
	for (int i=1; i < n; i++) {
		if (a[i][0] >= curx && a[i][1] >= curh) {
			curx = a[i][0];
			curh = a[i][1];
			res++;
		}
		else continue;
	}
	cout << res << endl;
	return 0;
}