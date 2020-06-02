#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool mycmp(const vector<int>& A, const vector<int>& B) {
	float a = 1.0*A[1] / A[0], b = 1.0*B[1] / B[0];
	return a > b;
}

int main() {
	int N, T;
	int v, l, c;//价格，满意度数量
	while (cin >> N>>T) {
		vector<vector<int>> a;
		for (int i = 0; i < N;i++) {
			cin >> v >> l >> c;
			a.push_back({ v,l,c });
		}

		sort(a.begin(), a.end(), mycmp);//将食品按性价比从大到小排列
		int s = 0,r=T;
		for (int i = 0; i < a.size(); i++) {
			int buys = 0;
			if (r >= a[i][0])
				buys = min(r / a[i][0], a[i][2]);
			else
				continue;
			while((r-buys * a[i][0])<0)
				buys--;
			if (buys > 0&&i<a.size()-1) {
				int rb = r - buys * a[i][0];
				int rnb = r - (buys - 1)* a[i][0];
				if ((rnb / a[i + 1][0] - rb / a[i + 1][0])*a[i + 1][1] > a[i][1]) {
					buys--;
				}

			}
				r -= buys * a[i][0];
				s += buys * a[i][1];
		}
		cout << s << endl;
	}
	return 0;
}