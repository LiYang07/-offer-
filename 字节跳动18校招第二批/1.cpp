#include<iostream>
#include<vector>
#include<algorithm>
//题目：
//为了不断优化推荐效果，今日头条每天要存储和处理海量数据。假设有这样一种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，每个用户都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户）中，有多少用户对这类文章喜好值为kk。因为一些特殊的原因，不会出现一个查询的用户区间完全覆盖另一个查询的用户区间(不存在L1 <= L2 <= R2 <= R1L1 <= L2 <= R2 <= R1)。
////
//输入：
//第1行为n代表用户的个数 第2行为n个整数，第i个代表用户标号为i的用户对某类文章的喜好度 第3行为一个正整数q代表查询的组数, 第4行到第(3 + q)行，每行包含3个整数l, r, k代表一组查询，即标号为l <= i <= r的用户中对这类文章喜好值为k的用户的个数。 数据范围n <= 300000, q <= 300000n <= 300000, q <= 300000，k是整型。
//
//输出：
//一共q行，每行一个整数代表喜好值为k的用户的个数。
//第一题：用户喜好
//
//样例输入：
//5
//1 2 3 3 5
//3
//1 2 1
//2 4 5
//3 5 3
//样例输出：
//1
//0
//2
//-------------------- -
//作者：FlushHip
//来源：CSDN
//原文：https ://blog.csdn.net/flushhip/article/details/79416715 
//版权声明：本文为博主原创文章，转载请附上博文链接！
using namespace std;

bool sort_cmp(const pair<int, int>&A, const pair<int, int>&B) {
	
	return A.first == B.first ?   A.second < B.second : A.first < B.first;
}

struct find_first_cmp
{
	bool operator()(const pair<int, int> &P, int k) const
	{
		return P.first < k;
	}

	bool operator()(int k, const pair<int, int> &P) const
	{
		return k < P.first;
	}
};
struct find_second_cmp {
	bool operator()(const pair<int, int> &P, int k) const
	{
		return P.second < k;
	}

	bool operator()(int k, const pair<int, int> &P) const
	{
		return k < P.second;
	}
};


//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int> > scores;
//	for (int i = 1; i <= n; i++) {
//		int k;
//		cin >> k;
//		scores.emplace_back(k, i);
//	}
//
//	sort(scores.begin(), scores.end(), sort_cmp);
//	int search_nums;
//	cin >> search_nums;
//	for (int i = 0; i < search_nums; i++) {
//		int low, high, k;
//		cin >> low >> high >> k;
//		auto bounds = equal_range(scores.begin(), scores.end(), k, find_first_cmp{});
//		cout << upper_bound(bounds.first, bounds.second, high, find_second_cmp{}) - lower_bound(bounds.first, bounds.second, low, find_second_cmp{}) << endl;
//	}
//
//
//	return 0;
//
//}