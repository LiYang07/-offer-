#include<iostream>
#include<algorithm>

using namespace std;

//int main() {
//	
//	int N, A, X;
//	while (cin >> N >> A >> X) {
//		int sum = 0;
//		for (int i = 0; i < N; i++) {
//			int temp;
//			cin >> temp;
//			sum += temp;//解决bug需要的总时间
//		}
//		int extra = 60 * X*A;
//		int normal = (8 - X) * 60;
//		if (sum > extra + normal) {
//			cout << 0 << endl;
//			continue;
//		}
//		else {
//			if (extra >= sum) {
//				if (sum%A == 0)
//					cout << sum / A << endl;
//				else
//					cout << sum / A + 1 << endl;
//				continue;
//			
//			}
//			else {
//				int res = 0;
//				res += extra / A;
//				res += sum - extra;
//				cout << res << endl;
//				continue;
//			}
//		}
//	}
//	return 0;
//}