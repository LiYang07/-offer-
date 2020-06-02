#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> hash;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		hash[a[i]] = i;
	}
	map<int, int> hash_cpy=hash;
	int res1 = 0,res2=0, r = n,l=0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (hash[a[i]] > hash[a[i + 1]]) {
			hash[a[i+1]] = r++;
			res1++;
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (hash_cpy[a[i]] < hash_cpy[a[i-1]]) {
			hash_cpy[a[i-1]] = l--;
			res2++;
		}
	
	}
	cout <<min(res1,res2)<< endl;
	return 0;
}