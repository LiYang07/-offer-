//输入两个链表，找出它们的第一个公共结点。

#include<iostream>
#include<stack>

using namespace std;
//两个思路：
//1用两个辅助栈俩存储当前结点，然后同时pop（），直到pop后两个栈顶为不同元素时，返回上一个top值
//2先遍历两个链表，得到长度，然后再在较长的链表上先走长出的步数，再同时走，找到第一个相等的结点即为公共结点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		stack<ListNode*> nodeStack1;
		stack<ListNode*> nodeStack2;
		ListNode*cur1 = pHead1;
		ListNode*cur2 = pHead2;
		while (cur1) {
			nodeStack1.push(cur1);
			cur1 = cur1->next;
		}
		while(cur2){
			nodeStack2.push(cur2);
			cur2 = cur2->next;
		}
		ListNode* preTop=NULL;
		while (!nodeStack1.empty() && !nodeStack2.empty()) {
			if (nodeStack1.top()->val == nodeStack2.top()->val) {
				preTop = nodeStack1.top();
				nodeStack1.pop();
				nodeStack2.pop();
			}
			else
				break;
			
		}
		return preTop;
	}
};

int main(){
	ListNode *phead1 = new ListNode(1), *pcur1 = phead1;
	for (int i = 2; i <= 7; i++) {
		pcur1->next = new ListNode(i);
		pcur1 = pcur1->next;
	}
	ListNode* phead2 = new ListNode(4);
	phead1->next = new ListNode(5);
	phead1->next->next = phead1->next->next->next;
	Solution s;
	cout << (s.FindFirstCommonNode(phead1, phead2))->val;
	system("pause");
}