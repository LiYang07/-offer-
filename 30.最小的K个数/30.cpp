//输入n个整数，找出其中最小的K个数。例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4, 。
#include<iostream>
#include<vector>
#include<queue>

//最简单的方法：先对输入数组进行快排，然后直接求前面n个数，时间复杂度nlogn
using namespace std;
//class Solution {//可以维护一个双边队列，使得较大的数放在队尾
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//
//		if (k > input.size()||input.empty()||k==0)
//			return {};
//		if (k == input.size())
//			return input;
//		_minList.push_front(input[0]);
//		for (int i = 1; i < input.size(); i++) {
//			if (input[i] <= _minList.back()) {
//				_minList.push_front(input[i]);
//				if (_minList.size() > k)
//					_minList.pop_back();
//			}
//			
//		}
//		return vector<int>(_minList.begin(), _minList.end());
//		
//	}
//private:
//	deque<int> _minList;
//};

//改进版本，避免队尾元素过小，实际上最小的k个数无法进入的问题
//补充此版本仍然无法解决，可以用优先队列解决
//优先队列实际上是堆实现
//升序队列
//priority_queue <int, vector<int>, greater<int> > q;
//降序队列，默认构造，大顶堆
//priority_queue <int, vector<int>, less<int> >q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）

class Solution {//用大顶堆来实现对当前最小的几个元素的存储
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

		if (k > input.size() || input.empty() || k == 0)
			return {};
		if (k == input.size())
			return input;
		for (int i = 0; i < input.size(); i++) {
			_minList.push(input[i]);
			if (_minList.size() > k)
				_minList.pop();

			}
		vector<int> res;
		while (!_minList.empty()) {
			res.push_back(_minList.top());
			_minList.pop();
		}
		return res;
	}

private:
	priority_queue<int> _minList;
};

int main() {
	unsigned char i = 255;
	cout << int(++i) << endl;

	Solution solu;
	vector<int> res=solu.GetLeastNumbers_Solution({ 4,5,1,6,2,7,3,8 }, 4);
	for (auto i : res)
		cout << i << endl;
	system("pause");
	return 0;
}