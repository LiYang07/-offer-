#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

typedef unsigned long long ull;
using namespace std;

//int main() {
//	std::ios::sync_with_stdio(false);
//
//	double in;
//	cin >> in;
//	int res = 0;
//	while (in != 1) {
//		double temp = sqrt(in);
//		ull temp_ull = (ull)(temp);
//		double diff = temp - temp_ull;
//		if (diff < 0.0000001)
//		{
//			in = temp;
//			res++;
//		}
//		else {
//			int gap = in - temp_ull * temp_ull;
//			in -= gap;
//			res += gap;
//		}
//	}
//	cout << res;
//	system("pause");
//	return 0;
//}