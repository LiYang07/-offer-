//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。
#include<iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		m_pre = pre;
		m_vin = vin;
		return reConstructCore(0, pre.size() - 1, 0, vin.size() - 1);
	}
private:
	TreeNode* reConstructCore(int preBegin, int preEnd, int vinBegin, int vinEnd) {
		int rootValue = m_pre[preBegin];
		TreeNode* root = new TreeNode(rootValue);
		if (preBegin == preEnd) {
			if (vinBegin == vinEnd && m_pre[preBegin] == m_vin[vinBegin])
				return root;
			else
				return NULL;//输入有误，可以选择抛出异常
		}

		//寻找根节点在当前子树中的位置，以划分左右子树
		int offset = 0;
		while (offset <= vinEnd - vinBegin) {
			if (m_vin[vinBegin + offset] == rootValue)
				break;
			++offset;
		}
		int leftLen = offset, rightLen = vinEnd - vinBegin - offset;
		if (offset > vinEnd - vinBegin)//输入有误
			return NULL;
		if (leftLen > 0)//存在左子树
		{
			root->left = reConstructCore(preBegin + 1, preBegin + leftLen, vinBegin, vinBegin + leftLen - 1);
		}
		if (rightLen > 0)//存在右子树
		{
			root->right = reConstructCore(preBegin + leftLen + 1, preEnd, vinBegin + leftLen + 1, vinEnd);
		}

		return root;
	}
	vector<int> m_pre;
	vector<int> m_vin;
};
