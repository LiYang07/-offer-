//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
	void push(int value) {
		if (data.empty()) {
			minVal = value;
		}
		else
			minVal = minVal < value ? minVal : value;
		data.push(value);
		min_stack.push(minVal);
	}
	void pop() {
		data.pop();
		min_stack.pop();
	}
	int top() {
		return data.top();
	}
	int min() {
		return min_stack.top();
	}
private:
	stack<int> min_stack;
	stack<int> data;
	int minVal;
};

int main(){
	Solution s;
	vector<int> vec = { 11,25,9,8,8,14,36,29,14,5,7,2,13,99 };
	for (auto i : vec)
		s.push(i);
	cout << s.min() << " " << s.top() << endl;
	for (int i = 0; i < 7; i++)
		s.pop();
	cout << s.min() << " " << s.top()<<endl;
	system("pause");
}