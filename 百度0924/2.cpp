#include <vector>
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<ull> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int res = 0;
	while (vec[0] >= n) {
		int temp = vec[1] > n ? vec[1] : n;
		int	times1 = (vec[0] - temp) / (n + 1) + 1;
		int times2 = vec[0] / (n + 1) + 1;
		int times = times1 < times2 ? times1 : times2;
		vec[0] = vec[0] - times * n;
		for (int i = 1; i < n; i++)
			vec[i] += times;
		res += times;
		sort(vec.begin(), vec.end(), greater<int>());
	}
	cout << res << endl;

}
