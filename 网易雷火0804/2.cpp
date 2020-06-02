#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
vector<vector<pair<int, int>>> tree(11);

int main() {
	int p, q;
	cin >> p >> q;
	if (p == 1 || q == 1) {
		if (p == 1)
			cout << q << " " << 1;
		if (q == 1)
			cout << p << " " << pow(2, p - 1);
		return 0;
	}
	
	tree[0].push_back( make_pair<int,int>(1,2));
	//先构建树的一半
	for (int i = 1; i <=10; i++) {
		int j;
		for ( j = 0; j <pow(2, i - 1);j++) {
			tree[i].push_back({ tree[i - 1][j].first, tree[i - 1][j].first + tree[i - 1][j].second });
		}

		for (; j < pow(2, i); j++) {
			tree[i].push_back({ tree[i - 1][j- pow(2, i - 1)].second, tree[i][pow(2,i) - 1 - j].second });
		}
	
	}

	for (int i = 0; i < tree.size(); i++){
		for (int j = 0; j < tree[i].size(); j++) {
			if (p == tree[i][j].first && q == tree[i][j].second) {
				cout << i + 2 << " " << j + 1;
				return 0;
			}
			if (p == tree[i][j].second && q == tree[i][j].second) {
				cout << i + 2 << " " << pow(2, i + 1) - j + 1;
				return 0;
			}
		}
	}
}