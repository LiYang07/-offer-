#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> nums;
	vector<string> ops;
	int num;
	char op;
	for (int i = 0; i < n - 1; i++) {
		cin >> num >> op;
		nums.push_back(num);
		ops.push_back(op);
	}
	cin >> num;
	nums.push_back(num);
	vector<string> subs;//´æ´¢subs
	int last= 0;
	for (int i = 0; i < n - 1; i++) {
		if (ops[i] == "+" || ops[i] == "-")continue;
		last = i;
		subs.push_back({});
		for (int j = 0; j <= i - 1; j++) {
			if (j > 0)subs.push_back( ops[j - 1] + to_string(nums[j]));
			else if (nums[j] >= 0) subs.push_back("+ " + to_string(nums[j]));
			else 
		}

	}
}