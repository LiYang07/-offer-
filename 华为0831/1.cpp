#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>


using namespace std; 

//int main() {
//	int n=pow(2,31);
//	//cin >> n;
//	string strn;
//	int test = 1;
//	for (int i = 0; i < sizeof(n) * 8; i++) {
//		if (test&n)
//			strn.push_back('1');
//		else
//			strn.push_back('0');
//		test = test << 1;
//	}
//	vector<int> res;
//	for (int i = 0; i < strn.size() - 3;i++) {
//		if (strn.substr(i, 3) == "101")
//			res.push_back(i);
//	}
//		if (res.size())
//			cout << res.size() << " " << res[0] << endl;
//		else
//			cout << 0 << " " <<- 1 << endl;
//		return 0;
//}
////int main()
////{
////	int n;
////	cin >> n;
////	vector<int> res;
////	int cnt=29;
////	int test = 5 << 29;
////	while (n) {
////		if ((n & test)==test) {
////			res.push_back(cnt);
////		}
////		cnt--;
////		n = n << 1;
////	}
////	if (res.size())
////		cout << res.size() << " " << res.back() << endl;
////	else
////		cout << 0 << " " - 1 << endl;
////	system("pause");
////	return 0;
////}