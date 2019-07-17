//判断二叉树是否为平衡二叉树
#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//同上一题，此题可以递归的判断每一棵子树是否为平衡树
//判断每一棵树是否为平衡二叉树，反复调用TreeDepth,这样存在大量的重复运算
//此方法在牛课上不通过，递归调用层数过深。
//class Solution {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot = NULL)
//			return true;
//		int nleft = TreeDepth(pRoot->left);
//		int nright = TreeDepth(pRoot->right);
//		if (abs(nleft - nright) > 1) return false;
//		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//	}
//private:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (pRoot == NULL)
//			return 0;
//		int nleft = TreeDepth(pRoot->left);
//		int nright = TreeDepth(pRoot->right);
//		return nleft > nright ? nleft + 1 : nright + 1;
//	}
//};


//自带剪枝的算法，从底向上遍历，如果有某一棵子树为不平衡树，则直接返回
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		return getDepth(pRoot) != -1;
	}
private:
	int getDepth(const TreeNode* proot) {
		if (proot == NULL)
			return 0;
		int left = getDepth(proot->left);
		if (left == -1)
			return -1;
		int right = getDepth(proot->right);
		if (right == -1)
			return -1;
		return abs(left - right) > 1 ? -1 : (left > right ? left + 1 : right + 1);
	}
};