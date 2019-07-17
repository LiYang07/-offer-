#include<iostream>
#include<vector>

using namespace std;


//int main() {
//	int n;
//	cin >> n;
//	vector<int> rating;
//	int scores;
//	for(int i=0;i<n;i++)
//		rating.push_back(scores);
//
//	int count= 0;
//
//	//糖果集合
//	vector<int> candy(n, 1);
//	int sum = 0;
//	int num = 1;
//	int j;
//	//遍历每个小朋友
//	for (int i = 0; i < n; i++)
//	{
//		j = i;
//		//往前比对 求出应得最少糖果数
//		if (j >= 1 && candy[j] > candy[j - 1])
//		{
//			num++;
//		}
//		else
//		{
//			num = 1;
//		}
//		//开始往后比对，求出往后比对应得最少糖果数
//		int next = 1;
//		while (j < candy.n() - 1 && candy[j] > candy[j + 1])
//		{
//			j++;
//			next++;
//		}
//
//		num = num > next ? num : next;
//		//Console.WriteLine("num:" + num);
//		sum += num;
//	}
//	
//	cout << sum;
//	system("pause");
//	return 0;
//}

