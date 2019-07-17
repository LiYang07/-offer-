//负数用补码表示

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= (n - 1);//每次同n-1位与都会使最后一位1变零
			count++;
		}
		return count;
	}
};