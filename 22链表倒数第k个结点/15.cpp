#include<iostream>

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* frontNode = pListHead;
		int count = 0;
		while (frontNode&&count < k - 1) {
			frontNode = frontNode->next;
			count++;
		}
		if (count != k - 1 ||count ==k-1 &&frontNode==NULL)//没有K个结点
			return NULL;
		ListNode* behindNode = pListHead;
		while (frontNode->next)
		{
			frontNode = frontNode->next;
			behindNode = behindNode->next;
		}
		return behindNode;
	}
};

int main() {
	ListNode * head = new ListNode(1);
	ListNode *cur = head;
	for (int i = 2; i <=5; i++)
	{
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	Solution s;
	ListNode* ob=s.FindKthToTail(head, 6);
	if (ob)
		cout << ob->val;
	else
		cout << "NULL";
	system("pause");
}