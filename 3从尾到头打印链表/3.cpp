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

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		printCore(head, res);
		return res;
	}
private:
	void printCore(ListNode*node, vector<int>&arrayList) {
		if (node == NULL)
			return;
		else
			 printCore(node->next, arrayList);
		arrayList.push_back(node->val);
	}
};

int main() {
	ListNode head(67);
	head.next = new ListNode(0);
	head.next->next = new ListNode(24);
	head.next->next->next = new ListNode(58);
	Solution s;

	vector<int> res = s.printListFromTailToHead(&head);
	for (auto elem : res)
		cout << elem << endl;
	system("pasue");
}