//LL今天心情特别好, 因为他去买了一副扑克牌, 发现里面居然有2个大王, 2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌, 想测测自己的手气, 
//看看能不能抽到顺子, 如果抽到的话, 他决定去买体育彩票, 嘿嘿！！“红心A, 黑桃3, 小王, 大王, 方片5”, “Oh My God!”不是顺子.....
//LL不高兴了, 他想了想, 决定大\小 王可以看成任何数字, 并且A看作1, J为11, Q为12, K为13。上面的5张牌就可以变成“1, 2, 3, 4, 5”(大小王分别看作2和4), “So Lucky!”。
//LL决定去买体育彩票啦。 现在, 要求你使用这幅牌模拟上面的过程, 然后告诉我们LL的运气如何，
//如果牌能组成顺子就输出true，否则就输出false。为了方便起见, 你可以认为大小王是0。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {//主要思路，先排序，然后再统计0的个数，顺子中空缺的个数，如果空缺数小于等于0的数量，那么可以排成顺子
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty())return false;//又没有考虑到数组为空的特殊情况
		sort(numbers.begin(), numbers.end());
		int zeroCount ;
		for (zeroCount = 0; zeroCount < numbers.size(); ++zeroCount)
			if (numbers[zeroCount] != 0)break;
		if (zeroCount == numbers.size()) return true;
		int blanks=0;
		for (int i = zeroCount + 1; i < numbers.size(); i++) {
			
			blanks += numbers[i] - numbers[i - 1]-1;
			if (blanks > zeroCount || numbers[i] == numbers[i - 1])
				return false;
		}
		return true;
		
	}
};

int main() {
	Solution s;
	cout << s.IsContinuous({ 1,3,0,0,5 }) << s.IsContinuous({ 4,6,6,0,5 });
	system("pause");
}