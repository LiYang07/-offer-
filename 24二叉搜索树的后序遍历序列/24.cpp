//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。
#include<iostream>
#include<vector>

using namespace std;

//此题应该充分利用二叉搜索树的特性
//后续遍历后，左子树所有值小于根，右子树所有值大于根
//可依照此特性递归遍历整棵树
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		_sequence = sequence;
		return isBSTcore(0,sequence.size()-1);
	}
private:
	bool isBSTcore(int treeBegin, int treeEnd) {
		if (treeEnd - treeBegin<=0)
			return true;
		int rootVal = _sequence[treeEnd];
		int leftEnd, rightBegin;
		for (rightBegin = treeBegin; rightBegin < treeEnd ; rightBegin++)
			if (_sequence[rightBegin] > rootVal)break;
		for (int i=rightBegin+1; i <= treeEnd-1; i++)
		{
			if (_sequence[i] < rootVal) return false;
		}
			
		return isBSTcore(treeBegin, rightBegin - 1) && isBSTcore(rightBegin, treeEnd - 1);
	}

	vector<int> _sequence;
};

int main() {
	unsigned int a = 1;
	signed int b = -3;
	cout << a + b << endl;

	vector<int> seq = {5,8,6,11,14,13,9};
	Solution s;
	cout<<s.VerifySquenceOfBST(seq)<<endl;
	system("pause");
	return 0;
}