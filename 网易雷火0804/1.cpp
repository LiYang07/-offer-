#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//int main() {
//	vector<vector<int> > win;//存放窗口的左上坐标以及偏移
//	int n, m,x,y,w,h;
//	cin >> n >> m;
//	int count = 1;
//	while (n--) {
//		cin >> x >> y >> w >> h;
//		win.push_back({ x,y,w,h,count});
//		count++;
//	}
//
//	while (m--) {
//		cin >> x >> y;
//		int i;
//		for (i = win.size()-1; i >= 0; i--) {
//			if (x >= win[i][0] && x <= win[i][0] + win[i][2] && y >= win[i][1] && y <= win[i][1] + win[i][3])
//				break;
//		}
//		if (i >= 0)
//		{
//			cout << win[i][4] << endl;
//			vector<int> temp = win[i];
//			win.erase(win.begin() + i);
//			win.push_back(temp);
//		}
//		else cout << -1<<endl;
//	
//	}
//	return 0;
//}