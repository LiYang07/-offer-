//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//镜像树的先左到右遍历与先右后左遍历结果是相同的（包含NULL结点），为方便写递归，用前序遍历
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetricalCore(pRoot, pRoot);
	}
private:
	bool isSymmetricalCore(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetricalCore(pRoot1->left, pRoot2->right) && isSymmetricalCore(pRoot1->right, pRoot2->left);
	}
};