//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {//头结点也有可能会被删除掉
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode *preNode = NULL;
		ListNode *pNode = pHead;
		while (pNode != NULL) {
			ListNode* pNext = pNode->next;
			bool needDelete = false;
			if (pNext != NULL && pNext->val == pNode->val)
				needDelete = true;
			if (!needDelete) {
				preNode = pNode;
				pNode = pNode->next;
			}
			else {
				int val = pNode->val;
				ListNode* pToBeDel = pNode;
				while(pToBeDel!=NULL&&pToBeDel->val==val){
					pNext = pToBeDel->next;
					delete pToBeDel;
					pToBeDel = NULL;
					pToBeDel = pNext;
				}
			}
			if (preNode == NULL)//头结点被删除了
				pHead = pNext;
			else
				preNode->next = pNext;
			pNode = pNext;
			
		}
		return pHead;
	}
};
int main() {

		ListNode *head = new ListNode(1);
		ListNode* cur = head;
		for (int i = 0; i < 5; i++)
		{
			cur->next = new ListNode(1);
			cur = cur->next;
		}
		cur->next = new ListNode(2);
		Solution s;
		s.deleteDuplication(head);
		system("pause");
}