#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

bool isTest[100][]


int main() {
	std::ios::sync_with_stdio(false);
	int t,n;
	bool flag = false;
	cin >> t;
	while ((t--) > 0) {
		flag = false;
		cin >> n;
		if (n % 2 == 0) {
			cout << -1;
			continue;
		}
		int len = n >> 1;
		for (int x = 0; x <= len; x++) {
			for (int y = x + 1; y < n; y++) {
				int temp = (y - x)*(y + x);
				if (temp == n) {
					cout << y;
					flag = true;
					break;
				}
				else if (temp > n) {
					break;
				}

			}
		
		}
		if (!flag)cout << -1;
	}
	system("pause");
	return 0;
}