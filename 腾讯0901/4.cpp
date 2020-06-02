#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main() {
	int n,t;
	cin >> n;
	vector<int> w;
	for (int i = 0; i < n; i++) {
		cin >> t;
		w.push_back(t);
	}
	map<pair<int, int>, int>  mins;
	for (int i = 0; i < n; i++)
		mins[make_pair(i, i)] = w[i];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			mins[make_pair(i, j)] = min(mins[{i, j - 1}], mins[{j, j}]);
	}
	vector<int> sums(n+1,0);//Ç°×ººÍ
	sums[1] = w[0];
	for (int i = 1; i < n; i++) {
		sums[i+1]=sums[i] + w[i];
	}
	int ans = 0;
	for (auto e : mins) {
		ans = max(ans, (sums[e.first.second + 1] - sums[e.first.first])*e.second);
	}
	cout << ans << endl;
	return 0;
}