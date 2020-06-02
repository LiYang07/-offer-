#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
const int N = 1010;

int a[N];

//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int temp;
//		cin >> temp;
//		a[i] = temp;
//	}
//	int A=0,B = 0;//存放当前A和B末尾存放的元素;
//	int l = 0, r = n - 1;
//	long sa = 0, sb = 0;
//
//	while (l <= r) {
//		int cl = abs(a[l] - A), cr = abs(a[r] - A);
//		bool flagl;
//		
//		flagl = cl > cr  ? (l + 1 <= r && r - 1 >= l) ? (abs(a[l + 1] - B) > abs(a[r - 1] - B) && abs(a[l + 1] - B) - abs(a[r - 1] - B) > cl - cr)?
//
//		if (cl > cr) {
//			if (l + 1 <= r && r - 1 >= l && (abs(a[l + 1] - B) > abs(a[r - 1] - B) && abs(a[l + 1] - B) - abs(a[r - 1] - B) > cl - cr))//选左边的损失大于右边
//			{
//				A = a[r];
//				sb += cr;
//				r--;
//				flag = true;
//			}
//			else {
//				A = a[l];
//				sa += cl;
//				l++;
//				flag = true;
//			}
//		}
//		else
//			
//		if (l <= r) {
//			cl = abs(a[l] - B), cr = abs(a[r] - B);
//			if (cl > cr && (abs(a[l + 1] - A) < abs(a[r - 1] - A) || abs(a[r - 1] - A) - abs(a[l + 1] - A) < cl - cr)) {
//				B  = a[l];
//				sb += cl;
//				l++;
//			}
//			else {
//				B = a[r];
//				sb += cr;
//				r--;
//			}
//		
//		}
//	}
//	cout << sa << " " << sb << endl;
//	system("pause");
//	return 0;
//}