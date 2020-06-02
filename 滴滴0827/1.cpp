//#include<iostream>
//#include<algorithm>
//#include<numeric>
//#include<vector>
//
//using namespace std;
//
//
//vector<int> getColmax(vector<vector<int>> &tasks){
//	int rows = tasks.size(), cols = tasks[0].size();
//	vector<int> res;
//	for (int i = 0; i < cols; i++) {
//		int maxval = -1;
//		for (int j = 0; j < rows; j++)
//			maxval = max(maxval, tasks[j][i]);
//		res.push_back(maxval);
//	}
//	return res;
//}
//
//int main() {
//	int n, m,t;
//	cin >> n >> m;
//	vector<vector<int> > tasks;
//	for (int i = 0; i < n; i++) {
//		tasks.push_back({});
//		for (int j = 0; j < m; j++)
//		{
//			cin >> t;
//			tasks[i].push_back(t);
//		}
//	}
//	vector<int> res = getColmax(tasks);
//	cout<<accumulate(res.begin(), res.end(), 0)<<endl;
//	return 0;
//}
//
