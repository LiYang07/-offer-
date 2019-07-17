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
class Solution {//思路1：将二叉树所有节点放入按顺序排列的容器中，然后再连接
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree)
			return NULL;
		build_list(pRootOfTree);
		if (nodeList.size() == 1)
			return nodeList[0];
		for (int i = 1; i < nodeList.size() - 1; i++) {
			nodeList[i]->right = nodeList[i + 1];
			nodeList[i]->left = nodeList[i - 1];
		}
		nodeList[0]->right = nodeList[1];
		nodeList[nodeList.size() - 1]->left = nodeList[nodeList.size() - 2];
		return nodeList[0];
	}
private:
	void build_list(TreeNode* node) {//中序遍历将
		if (!node)
			return;
		build_list(node->left);
		nodeList.push_back(node);
		build_list(node->right);
	}
	vector<TreeNode*> nodeList;
};