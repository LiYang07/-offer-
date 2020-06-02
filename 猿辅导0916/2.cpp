#include<iostream>
#include<algorithm>


using namespace std;

const int N = 200005;
int a[N];
long sums[N];
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sums[i] = a[i] + sums[i - 1];
	}
	int res = 0;
	int front = 1, back = 1;
	while (n-front+1 > res) {
		while (front > back && back<n )++back;
		if (sums[back] - sums[front - 1] <= s) {
			res = max(res, back - front + 1);
			if(back<n)back++;
		}
		else
		{
			if (front<n && front<=back )++front;
		}
	}
	cout << res << endl;
	return 0;
}