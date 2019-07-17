//作为一个手串艺人，有金主向你订购了一条包含n个杂色串珠的手串——每个串珠要么无色，要么涂了若干种颜色。
//为了使手串的色彩看起来不那么单调，金主要求，手串上的任意一种颜色（不包含无色），在任意连续的m个串珠里至多出现一次（注意这里手串是一个环形）。手串上的颜色一共有c种。现在按顺时针序告诉你n个串珠的手串上，每个串珠用所包含的颜色分别有哪些。请你判断该手串上有多少种颜色不符合要求。即询问有多少种颜色在任意连续m个串珠中出现了至少两次。
//
//
//输入描述 :
//第一行输入n，m，c三个数，用空格隔开。(1 <= n <= 10000, 1 <= m <= 1000, 1 <= c <= 50) 接下来n行每行的第一个数num_i(0 <= num_i <= c)表示第i颗珠子有多少种颜色。接下来依次读入num_i个数字，每个数字x表示第i颗柱子上包含第x种颜色(1 <= x <= c)
//
//输出描述 :
//	一个非负整数，表示该手链上有多少种颜色不符需求。
//
//	输入例子1 :
//5 2 3
//3 1 2 3
//0
//2 2 3
//1 2
//1 3
//
//输出例子1:
//2
//
//例子说明1 :
//	第一种颜色出现在第1颗串珠，与规则无冲突。
//	第二种颜色分别出现在第 1，3，4颗串珠，第3颗与第4颗串珠相邻，所以不合要求。
//	第三种颜色分别出现在第1，3，5颗串珠，第5颗串珠的下一个是第1颗，所以不合要求。
//	总计有2种颜色的分布是有问题的。
//	这里第2颗串珠是透明的。

#include<iostream>
#include<map>
#include<vector>

using namespace std;

//用一个map存储当前搜索范围内所有颜色出现的次数
//int main() {
//	int n, m, c;
//	cin >> n >> m >> c;
//	vector<vector<int> > balls(n + m - 1);
//	for (int i = 0; i < n; i++) {
//		int color_nums,color;
//		cin >> color_nums;
//		for (int j = 0; j < color_nums; j++)
//		{
//			cin >> color;
//			balls[i].push_back(color);
//		}
//		for (int i = 0; i < m - 1; i++)
//			balls[n + i] = balls[i];//将容器头接在尾部
//	}
//	map<int, int> cur_map, res_map;
//	for (int i = 0; i < n; i++) {
//		if (i == 0) {
//			for (int j = 0; j < m; j++)
//			{
//				for(int k=0;k<balls[j].size();k++)
//					if(++cur_map[balls[j][k]]>1)
//						res_map[balls[j][k]]++;
//			}
//		}
//		else
//		{
//			for (int j = 0; j < balls[i - 1].size(); j++)
//				cur_map[balls[i - 1][j]]--;
//			for(int j=0;j<balls[i+m-1].size();j++)
//				if(++cur_map[balls[i+m-1][j]]>1)
//					res_map[balls[i + m - 1][j]]++;
//		}
//	}
//	cout << res_map.size();
//	system("pause");
//	return 0;
//
//}