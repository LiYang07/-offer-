#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;



//bfs
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> peo(n + 1);
	vector<vector<int>> lan(m + 1);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		peo[a].push_back(b);
		lan[b].push_back(a);
	}
	vector<bool> flag(n + 1, false);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (flag[i] == false) {
			res++;
			queue<int> q;
			q.push(i);
			flag[i] = true;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int i = 0; i < peo[cur].size(); i++) {
					for (int j = 0; j < lan[peo[cur][i]].size(); j++) {
						if (flag[lan[peo[cur][i]][j]] == false) {
							q.push(lan[peo[cur][i]][j]);
							flag[lan[peo[cur][i]][j]] = true;
						}
					}
				}
			}
		}
	}
	if (k == 0)
		cout << res << endl;
	else
		cout << res - 1 << endl;
	system("pause");
	return 0;
}
