#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

using namespace std;

//int main() {
//	int n, k;
//	cin >> n;
//	vector<int> nums;
//	for (int i = 0; i < n; i++) {
//		int val;
//		cin >> val;
//		nums.push_back(val);
//	}
//	cin >> k;
//	if (k >= n) {
//		cout << "null";
//		return -1;
//	}
//
//	ListNode *head = new ListNode(0);
//	head->val = nums[0];
//	ListNode* cur=head;
//	for (int i = 1; i < nums.size();i++) {
//		cur->next = new ListNode(nums[i]);
//		cur = cur->next;
//	}
//	ListNode* frontNode = head;
//	int count = 0;
//	while (frontNode&&count <k) {
//		frontNode = frontNode->next;
//		count++;
//	}
//	//if (count != k - 1 || count == k - 1 && frontNode == NULL)//没有K个结点
//	//	return NULL;
//	ListNode* behindNode =head;
//	while (frontNode->next)
//	{
//		frontNode = frontNode->next;
//		behindNode = behindNode->next;
//	}
//	cout << behindNode->val;
//	return 0;
//}
