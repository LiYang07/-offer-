//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//n <= 39

class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1)
			return n;
		int fn0 = 0, fn1 = 1, fn;
		for (int i = 2; i <= n; i++) {
			fn = fn0 + fn1;
			fn0 = fn1;
			fn1 = fn;
		}
		return fn;
	}
};