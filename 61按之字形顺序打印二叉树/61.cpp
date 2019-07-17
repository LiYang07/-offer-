#include<iostream>
#include<vector>
#include<stack>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


using namespace std;
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL)
			return {};
		stack<TreeNode*> *s=new stack<TreeNode*>[2];//存储奇数层的结点值
		vector<vector<int> > res;
		res.push_back(vector<int>());
		s[0].push(pRoot);
		int current = 0;
		int next = 1;
		while (!s[0].empty() || !s[1].empty()) {
			TreeNode* node = s[current].top();
			if (current==0) {//当前需要pop的是奇数行,左边先入栈
				if (node->left!=NULL)
					s[next].push(node->left);
				if (node->right!=NULL)
					s[next].push(node->right);
			}
			else
			{
				if (node->right!=NULL)
					s[next].push(node->right);
				if (node->left!=NULL)
					s[next].push(node->left);
			}
			res.back().push_back(node->val);
			s[current].pop();
			if (s[current].empty()) {
				current = 1-current;
				next = 1 - next;
				if (!s[current].empty())
					res.push_back(vector<int>());
			}

		}
		return res;
	}
};

int main() {
	TreeNode *tree = new TreeNode(8);
	tree->left = new TreeNode(6);
	tree->right = new TreeNode(10);
	tree->left->left = new TreeNode(1);
	tree->left->right = new TreeNode(2);
	tree->right->left = new TreeNode(3);
	tree->right->right = new TreeNode(4);
	tree->right->right->left = new TreeNode(9);
	tree->right->right -> right = new TreeNode(10);
	Solution s;
	s.Print(tree);

}