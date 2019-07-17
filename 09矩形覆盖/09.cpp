//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？


class Solution {
public:
	int rectCover(int number) {
		if (number <= 2)
			return number;
		int f1 = 1, f2 = 2, fn;
		for (int i = 3; i <= number; i++) {
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		return fn;
	}
};