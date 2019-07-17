//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {//主要思路，递归的方式来写
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{

		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		ListNode* pcurHead = NULL;
		if (pHead1->val <= pHead2->val)
		{
			pcurHead = pHead1;
			pcurHead->next = Merge(pHead1->next, pHead2);
		}
		else {
			pcurHead = pHead2;
			pcurHead->next = Merge(pHead1, pHead2->next);
		}
		return pcurHead;
	}
};