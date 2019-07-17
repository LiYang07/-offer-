#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//此题不难，主要考对链表的操作
//首先找到换中的任意结点
//然后找环的长度
//最后再维护两个指针从头出发，一个先走换的长度，另外一个再出发，下次相遇的点就是环的入口。

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* meet = getmeetNode(pHead);
		if (meet == NULL)
			return NULL;
		int len = getCircleLenth(meet);
		ListNode *pAhead = pHead, *pBehind = pHead;
		while (len--) {
			pAhead = pAhead->next;
		}
		while (pAhead!=pBehind) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pAhead;
	}
private:
	ListNode* getmeetNode(ListNode* phead) {
		if (phead == NULL)
			return NULL;
		ListNode  *pSlow = phead->next;//后面的结点
		if (pSlow == NULL)
			return NULL;
		ListNode* pFast = pSlow->next;
		if (pFast == NULL)//如果连三个有效结点都没有，那么肯定没有换
			return NULL;
		while(pFast!=NULL&&pSlow!=NULL){
			if (pFast == pSlow)
				return pFast;
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast)
				pFast = pFast->next;
		}
		return NULL;//没有环
	}
	int getCircleLenth(ListNode* pHead) {//找到环的长度
		ListNode *cur = pHead;
		int count = 0;
		do {
			cur = cur->next;
			count++;
		} while (cur != pHead);
		return count;
	}
};