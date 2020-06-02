//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {//中序遍历递归地建立链表
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* LastOfList = NULL;
		ConvertCore(pRootOfTree, &LastOfList);
		while (LastOfList->left != NULL)
			LastOfList = LastOfList->left;
		return LastOfList;
	}
private:
	void ConvertCore(TreeNode* pRoot, TreeNode** LastOfList) {
		if (pRoot == NULL)
			return;
		TreeNode* pCur = pRoot;
		ConvertCore(pRoot->left, LastOfList);
		pCur->left = *LastOfList;
		if (*LastOfList != NULL)
			(*LastOfList)->right = pCur;
		*LastOfList = pCur;
		if(pRoot->right!=NULL)
			ConvertCore(pRoot->right, LastOfList);
	}
};

//class Solution {//思路2：将二叉树所有节点放入按顺序排列的容器中，然后再连接
//public:
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		if (!pRootOfTree)
//			return NULL;
//		build_list(pRootOfTree);
//		if (nodeList.size() == 1)
//			return nodeList[0];
//		for (int i = 1; i < nodeList.size() - 1; i++) {
//			nodeList[i]->right = nodeList[i + 1];
//			nodeList[i]->left = nodeList[i - 1];
//		}
//		nodeList[0]->right = nodeList[1];
//		nodeList[nodeList.size() - 1]->left = nodeList[nodeList.size() - 2];
//		return nodeList[0];
//	}
//private:
//	void build_list(TreeNode* node) {//中序遍历将
//		if (!node)
//			return;
//		build_list(node->left);
//		nodeList.push_back(node);
//		build_list(node->right);
//	}
//	vector<TreeNode*> nodeList;
//};