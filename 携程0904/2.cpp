//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include<algorithm>
//#include<string>
//#include<stack>
//
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//string resolve(string expr) {
//	string res="";
//	stack<char> stk;
//	string temp;
//	for (int i = 0; i < expr.size();i++) {
//		if (expr[i] == '(') {
//			if (stk.empty()) {
//				res += temp;
//				temp.clear();
//			}
//			stk.push('(');
//		}
//		else if (expr[i] == ')') {
//			if (stk.empty())
//				return "";
//			stk.pop();
//			reverse(temp.begin(), temp.end());
//		}
//		else {
//			temp.push_back(expr[i]);
//		}
//	}
//	if (stk.size()) return "";
//	res += temp;
//	return res;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	string res="abc((ur(de))oi)()ceh(el)lo";
//	cout << resolve(res);
//	system("pause");
//	return 0;
//
//}
