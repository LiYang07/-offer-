#include<iostream>

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