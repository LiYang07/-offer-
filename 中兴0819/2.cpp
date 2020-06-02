

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<int, int> occurs;//记录第一次出现的标号

bool mycmp(const pair<int, int> &A, const pair<int, int> &B) {
	if (A.second == B.second)
		return occurs[A.first] < occurs[B.first];
	return A.second > B.second;

}


vector<int> salary(int num, int *salaries) {
	map<int, int> counts;//记录出现的次数
	for (int i = 0; i < num; i++) {
		counts[salaries[i]]++;
		if (occurs[salaries[i]] == 0) occurs[salaries[i]] == i;
	}
	vector<pair<int, int>> pairs;//存放排好序的pair
	for (auto elem : counts) pairs.push_back(elem);
	sort(pairs.begin(), pairs.end(), mycmp);
	vector<int> res;//存放结果
	for (auto elem : pairs) {
		for (int i = 0; i < elem.second; i++)
			res.push_back(elem.first);
	}
	return res;
}
#include<iostream>

using namespace std;

unsigned long a[200];
int main(){
	int n;
	cin >> n;
	if (n > 200 || n < 1) {
		cout << 0;
		return 0;
	}
	a[0] = 1, a[1] = 1;
	for (int i = 2; i < n; i++)
		a[i] = a[i - 1] + a[i - 2];
	cout << a[n - 1];
	system("pause");
	return 0;
}