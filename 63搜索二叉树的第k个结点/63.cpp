//给定一棵二叉搜索树，请找出其中的第k小的结点。
//例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
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

class Solution {//二叉搜索树的中序遍历是递增的
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		return KthNodeCore(pRoot, k);
	}
private:
	TreeNode* KthNodeCore(TreeNode* Proot, int& k) {
		TreeNode* target = NULL;
		if(Proot->left!=NULL)
			target=KthNodeCore(Proot->left, k);
		if (target == NULL) {
			if (k == 1)
				target = Proot;
			k--;
		}
		if (target == NULL && Proot->right != NULL)
			target = KthNodeCore(Proot->right, k);
		return target;
	}

};

int main()
{
	TreeNode *tree = new TreeNode(8);
	tree->left = new TreeNode(6);
	tree->right = new TreeNode(10);
	tree->left->left = new TreeNode(5);
	tree->left->right = new TreeNode(7);
	tree->right->left = new TreeNode(9);
	tree->right->right = new TreeNode(11);
	Solution s;
	TreeNode*  pnode= s.KthNode(tree,2);
	cout << pnode->val;
	system("pause");
}