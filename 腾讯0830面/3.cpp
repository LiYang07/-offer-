//4. 检查两个表达式是否等价。表达式仅包含小写字母 ’a‘ - ’z‘, ’ + ‘, ’ - ‘, ’(‘, ’)‘，且表达式里的操作数仅有一个字符。
//例如：
//1) exp1 = ”a + b + c - a“, exp2 = ”(b + c)“, 返回 true;
//2) exp1 = ”a - b - c“, exp2 = ”a - (b + c)“, 返回 true

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

bool check(const char* exp1, const char* exp2);

int p1[26], n1[26], p2[26], n2[26]; //记录两个表达式中各个字符的数量

void count(const char* exp, int p[26], int n[26]) {
	stack<bool> stk;    //用一个stack来维护括号外层符号值
	while (*exp != '\0') {
		bool curispos = true;
		if (*exp == '-')
			curispos = false;
		else if (*exp == '(') {
			stk.push(stk.empty() ? curispos : curispos && curispos);
		}
		else if (*exp == ')') {
			stk.pop();
		}
		else if (*exp >= 'a' && *exp <= 'z') {
			bool flag = curispos;
			if (!stk.empty()) flag = curispos && stk.top();
			int index = *exp - 'a';
			if (flag) {
				if (n[index] > 0) n[index]--;
				else p[index]++;
			}
			else {
				if (p[index] > 0) p[index]--;
				else n[index]++;
			}
		}
		exp++;
	}
}

bool check(const char* exp1, const char* exp2) {
	count(exp1, p1, n1);
	count(exp2, p2, n2);
	for (int i = 0; i < 26; i++) {
		if (p1[i] != p2[i] || n1[i] != n2[i])return false;
	}
	return true;
}