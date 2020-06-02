#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=1010;
long long f[N];

//不相交的重要特性是，两个中间只隔一个入口的入口之间绝对不能修路
//是一个完整的递推关系
//f(2)=1
//f(4)=2*f(0)f(2)=2
//f(6)=2*f(0)f(4)+f(2)^2                  2是1-6  1-2对应的f(4)的情况  后面加的1是指 1-4连接时 f(4)的情况不成立了 只能相邻的点进行连接
//f(8)=2*f(6)f(0)+2*f(4)*f(2)
//f(10)=2*f(8)f(0)+2*f(6)*f(2)+f(4)^2
//f(12)=2*f(10)+2*f(8)*f(2)+ 2*f(6)*f(4)
//f(14)=2*f(12)+2*f(10)+2*f(8)*f(4)+f(6)^2
//f(16)=2*f(14)+2*f(12)+2*f(10)*f(4)+2*f(8)*f(6)
//int main() { 
//	int n;
//	cin >> n;
//	f[2] = 1;
//	f[4] = 2;
//	for (int i = 6; i <= n; i += 2) {
//		f[i] = 2 * f[i - 2];
//		for (int j = 2; j <= (i - 2) / 2; j += 2) {
//			if (i - 2 - j == j)
//				f[i] += f[j] * f[j];
//			else
//				f[i] += 2 * f[j]*f[i - 2 - j];
//		}
//	}
//	cout << f[n] % 1000000007 << endl;
//	system("pause");
//}
