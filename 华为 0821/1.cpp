#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	char a[16];
	for (int i = 0; i < 9; i++)
		a[i] = i-'0';
	for (int i = 10; i < 15; i++)
		a[i] = 'A' + i - 10;
	int n;
	cin >> n;
	string s;
	while (n) {
		s.push_back(a[n & 0xF]);
		n = n >> 4;
	}
	reverse(s.begin(), s.end());
	cout << s;
	system("pause");
	return 0;
}