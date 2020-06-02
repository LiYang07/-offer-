#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
//使用位图解决


int main() {
	int one=0;//存储每一位上是否有1
	int zerocount[32] = { 0 };//记录0的个数
	int n,state,x;
	cin >> n;
	while (n--) {
		cin >> state>>x;


		if (state == 1) {//插入
			one |= (x & 0Xffff);
			int count = 0;
			do{
				if ((x & 1)==0)//第一位为0
					++zerocount[count];
				x = x >> 1;
				count++;
			} while (x);
		}
		else {
			if ((x&one)<x)
				cout << "NO"<<endl;
			else {//检查是否有0的位置，0的数量大于等于1
				int count = 0;
				do {
					if ((x & 1)==0) 
						if (zerocount[count] < 1) {
							cout << "NO"<<endl;
							break;
						}
					x =x>> 1;
					count++;
				} while (x);
				if(x==0&&count>0)
					cout << "YES" << endl;
			}
		}
	}
	return 0;
}