//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		_expectNumber = expectNumber;
		FindPathCore(root);
		return res;
	}

private:
	void FindPathCore(TreeNode*root) {
		if (root==NULL)
			return;
		curPath.push_back(root->val);
		if (root->left)
			FindPathCore(root->left);
		if(root->right)
			FindPathCore(root->right);
		if(root->left==NULL&&root->right==NULL)//只有为叶节点时，才进行路径和判断
			if (accumulate(curPath.begin(), curPath.end(), 0) == _expectNumber)
				res.push_back(vector<int>(curPath.begin(), curPath.end()));
		curPath.pop_back();
	}
	vector<int> curPath;
	vector < vector<int>> res;
	int _expectNumber;
};



 void GetMemory(char *p)
 {
	 p = (char *)malloc(100);
 }
 void Test(void)
 {
	 char *str = NULL;
	 GetMemory(str);
	 strcpy(str, "hello world");
	 printf(str);
 }
 class A
 {
 public:
	 virtual void func(int val = 1)
	 {
		 std::cout << "A->" << val << std::endl;
	 }
	 virtual void test()
	 {
		 func();
	 }
 };
 class B : public A
 {
 public:
	 void func(int val = 0)
	 {
		 std::cout << "B->" << val << std::endl;
	 }
 };


int main() {
	/*ListNode head(1),node2(2),node3(3),node4(4),node5(5);
	head.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	Solution s;
	s.rotateRight(&head, 2);*/
	
		B*p = new B;
		p->test();
	system("pause");
	/*TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(1);
	
	Solution s;
	vector<vector<int> > res;
	res = s.FindPath(root, 7);
	for (auto vec : res){
		for (auto i : vec)
					cout << i << " ";
		cout << endl;
		}
	system("pause");
	return 1;*/
}


