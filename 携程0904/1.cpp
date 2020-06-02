//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//using namespace std;
//
//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int val) {
//		this->val = val;
//		this->next = NULL;
//	};
//};
//
///*请完成下面这个函数，实现题目要求的功能
//******************************开始写代码******************************/
//ListNode* partition(ListNode* head, int m) {
//	ListNode *dummy1 = new ListNode(-1);
//	ListNode *dummy2 = new ListNode(-1);
//	ListNode *p1 = dummy1, *p2 = dummy2;
//	ListNode *pnode = head;
//	while (pnode) {
//		if (pnode->val < m) {
//			p1->next = pnode;
//			p1 = p1->next;
//		}
//		else {
//			p2->next = pnode;
//			p2 = p2->next;
//		}
//		pnode = pnode->next;
//	}
//	if (dummy1->next == NULL)
//		return head;
//	p1->next = dummy2->next;
//	p2->next = NULL;
//	return dummy1->next;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	ListNode* head = NULL;
//	ListNode* node = NULL;
//	int m;
//	cin >> m;
//	int v;
//	while (cin >> v) {
//		if (head == NULL) {
//			node = new ListNode(v);
//			head = node;
//		}
//		else {
//			node->next = new ListNode(v);
//			node = node->next;
//		}
//	}
//	head = partition(head, m);
//	if (head != NULL) {
//		cout << head->val;
//		node = head->next;
//		delete head;
//		head = node;
//		while (head != NULL) {
//			cout << "," << head->val;
//			node = head->next;
//			delete head;
//			head = node;
//		}
//	}
//	cout << endl;
//	return 0;
//}
