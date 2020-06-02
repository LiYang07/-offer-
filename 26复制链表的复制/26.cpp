#include<iostream>

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		CopyNodes(pHead);
		connectRandomNodes(pHead);
		RandomListNode* pEvenHead = pHead->next;
		splitNodes(pHead);//拆分奇数链表
		return pEvenHead;
	}
private:
	void CopyNodes(RandomListNode* pHead){//首先复制所有的结点，
		RandomListNode* pNode = pHead;
		while(pNode!=NULL){
			RandomListNode* pCopy = new RandomListNode(pNode->label);
			pCopy->next = pNode->next;
			pNode->next = pCopy;
			pNode = pCopy->next;
		}
	}
	void connectRandomNodes(RandomListNode* pHead) {
		RandomListNode* pOrigin = pHead;
		RandomListNode* pCopy ;
		while (pOrigin != NULL) {
			pCopy = pOrigin->next;
			if (pOrigin->random != NULL)
				pCopy->random = pOrigin->random->next;
			pOrigin = pCopy->next;
		}
	}
	void splitNodes(RandomListNode* pHead){//拆分链表
		RandomListNode *pOdd = pHead;
		RandomListNode *pEven= pHead->next;
		while (pOdd != NULL) {
			pOdd->next = pEven->next;
			if (pOdd->next != NULL)
				pEven->next = pOdd->next->next;
			pOdd = pOdd->next;
			pEven = pEven->next;
		}
	}
};

int main() {
	RandomListNode* pHead = new RandomListNode(1);
	RandomListNode* pNode = pHead;
	for(int i=2;i<=5;i++){
		pNode->next = new RandomListNode(i);
		pNode = pNode->next;
	}
	pHead->next->random = pHead->next->next->next;
	pHead->next->next->random = pHead;
	Solution s;
	RandomListNode* clone=s.Clone(pHead);
	system("pause");
}