//输入一个链表，反转链表后，输出新链表的表头。
#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *pPre = NULL, *pCur = pHead, *pNext = pHead->next;
		while (pNext) {
			pCur->next = pPre;
			pPre = pCur;
			pCur = pNext;
			pNext = pNext->next;
		}
		pCur->next = pPre;
		return pCur;
	}
	//解法1，需要用到辅助空间，简单，但是没有用到链表的特性

	//ListNode* ReverseList(ListNode* pHead) {
	//	if (pHead == NULL || pHead->next == NULL)
	//		return pHead;
	//	//可以用一个容器来存储链表结点
	//	vector<ListNode*> nodeList;
	//	ListNode* cur = pHead;
	//	while (cur)
	//	{
	//		nodeList.push_back(cur);
	//		cur = cur->next;
	//	}
	//	for (int i = nodeList.size() - 1; i >= 1; i--)
	//		nodeList[i]->next = nodeList[i - 1];
	//	nodeList[0]->next = NULL;
	//	return nodeList.back();
	//}
};
typedef int *INTEGER;
int main() {
	int a = 3;
	a += a -= a * a;
	cout << a << endl;
	int i;
	for (i = 2; i != 0;)   printf("%d", i--);
	INTEGER p;


	ListNode * head = new ListNode(1);
	ListNode *cur = head;
	for (int i = 2; i <= 5; i++)
	{
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	Solution s;
	ListNode* ob = s.ReverseList(head);
	while (ob) {
		cout << ob->val << endl;
		ob = ob->next;
	}
	system("pause");
}