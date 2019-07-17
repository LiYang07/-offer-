#include<iostream>
#include<deque>
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
//两个思路，一个是利用队列，另外一个是递归
//class Solution {//利用队列，打印一个结点的同时将其子结点入队
//
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//		if (pRoot == NULL)
//			return { {} };
//		deque<TreeNode*> nodes;
//		nodes.push_back(pRoot);
//		int nextLevel = 0;
//		int toBeprint = 1;
//		vector<vector<int> > res;
//		res.push_back(vector<int>());
//		int curlevel = 0;
//		while (!nodes.empty()) {
//			TreeNode* node = nodes.front();
//			res[curlevel].push_back(node->val);
//			if (node->left != NULL) {
//				nodes.push_back(node->left);
//				++nextLevel;
//			}
//			if (node->right != NULL) {
//				nodes.push_back(node->right);
//				++nextLevel;
//			}
//			nodes.pop_front();
//			--toBeprint;
//			if (toBeprint == 0) {
//				if ((toBeprint = nextLevel) != 0)
//					res.push_back(vector<int>());
//				nextLevel = 0;
//				++curlevel;
//			}
//		}
//		return res;
//	}
//
//};

class Solution {//递归写法，按层递归
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		DepthPrint(pRoot, 1, res);
	}
private:
	void DepthPrint(TreeNode* pRoot, int depth, vector<vector<int> >& res) {
		if (pRoot == NULL)
			return;
		if (depth > res.size())
			res.push_back(vector<int>());
		res[depth-1].push_back(pRoot->val);
		DepthPrint(pRoot->left, depth + 1, res);
		DepthPrint(pRoot->right, depth + 1, res);
	
	}
};

int main() {
	std::ios::sync_with_stdio(false);//提升输入输出速率
}