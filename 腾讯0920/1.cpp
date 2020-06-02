//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool isvalid(int len, const string& str) {
//	if (len < 11)
//		return false;
//	size_t p = str.find('8');
//	if (p == string::npos)
//		return false;
//	if (len - p >= 11)
//		return true;
//	return false;
//
//}
//int main() {
//	int n;
//	cin >> n;
//	while (n) {
//		int len;
//		cin >> len;
//		string str;
//		cin >> str;
//		if (isvalid(len, str))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//		--n;
//	}
//	return 0;
//}