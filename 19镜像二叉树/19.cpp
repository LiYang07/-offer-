//操作给定的二叉树，将其变换为源二叉树的镜像。
//输入描述 :
//二叉树的镜像定义：源二叉树
//		8
//		/ \
//		6   10
//		/ \ / \
//		5  7 9 11
//镜像二叉树
//		8
//		/ \
//		10   6
//		/ \ / \
//		11 9 7  5

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
class Solution {//递归地交换每个父结点的左右子节点的val
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return;
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
};