#include<iostream>

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
//1没有右子树，又是其父节点的左子树，那么下一个就是其父节点
//2有右子树，那么下一个就是其最左的子节点
//3没有右子树，又是其父节点的右子树，就要一直向上遍历到某个是其父节点的左子树的结点，该结点的父结点即为下一个结点
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;

		if (pNode->right == NULL) {//没有右子树
			if (pNode->next == NULL)//也没有父亲结点
				return NULL;
			if ( pNode == pNode->next->left)//为其父结点的左孩子
				return pNode->next;
			else {
				TreeLinkNode* pParent = pNode;
				while (pParent->next != NULL && pParent == pParent->next->right)
					pParent = pParent->next;
				if (pParent != NULL && pParent->next != NULL)
					return pParent->next;
				return NULL; //没有下一个结点了
			}
		
		}
		else{
			TreeLinkNode* pNext = pNode->right;
			while (pNext->left != NULL)
				pNext = pNext->left;
			return pNext;
		}
	}
};