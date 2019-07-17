#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//如果将整数转化为char数组，还需要考虑整数的长度，这是此题最坑的地方，
//在反序列化的时候同样也要将char*转换为整数，还要考虑分割的问题，这个题的返回形式不好
class Solution {

public:
	char* Serialize(TreeNode *root) {
		vector<int> numbers;
		SerializeCore(root, numbers);
		return (char*)numbers.data();//此方法只对大端机器有效果
	}
	TreeNode* Deserialize(char *str) {
		int *numbers = (int*)str;
		return DeserializeCore(numbers);
	}
private:
	void SerializeCore(TreeNode* root,vector<int>& numbers) {
		if (root == NULL) {
			numbers.push_back(0x7777777);
			return;
		}
		else {
			numbers.push_back(root->val);
			SerializeCore(root->left, numbers);
			SerializeCore(root->right, numbers);
		}
		
	}
	TreeNode* DeserializeCore(int* numbers) {
		if (*numbers == 0x7777777) {
			++numbers;
			return NULL;
		}
		TreeNode* node = new TreeNode(*numbers);
		++numbers;
		node->left = DeserializeCore(numbers);
		node->right = DeserializeCore(numbers);
		return node;
	}
};

int main()
{
	TreeNode *tree = new TreeNode(8);
	tree->left = new TreeNode(6);
	tree->right = new TreeNode(10);
	tree->left->left = new TreeNode(1);
	tree->left->right = new TreeNode(2);
	tree->right->left = new TreeNode(3);
	tree->right->right = new TreeNode(4);
	tree->right->right->left = new TreeNode(9);
	tree->right->right->right = new TreeNode(10);
	Solution s;
	char *c = s.Serialize(tree);
	while (*c++ != '\0')
		cout << c;
	system("pause");
}