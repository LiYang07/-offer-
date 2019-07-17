//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
#include<vector>
#include<deque>
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
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		deque<TreeNode*> printDeq;
		printDeq.push_back(root);
		while (!printDeq.empty()) {
			TreeNode* pNode = printDeq.front();//入队
			res.push_back(pNode->val);
			printDeq.pop_front();//出队的同时将其左右结点依次入队
			if (pNode->left)
				printDeq.push_back(pNode->left);
			if (pNode->right)
				printDeq.push_back(pNode->right);
		}
		return res;
	}
};