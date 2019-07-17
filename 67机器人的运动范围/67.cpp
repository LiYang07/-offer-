#include<iostream>
#include<cstring>

using namespace std;
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[] visited;
		return count;
	}
private:
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
		int count = 0;
		if(row>=0&&row<rows&&col>=0&&col<cols&&getDigitSum(col)+getDigitSum(row)<=threshold&&!visited[row*cols+col]){
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +
				movingCountCore(threshold, rows, cols, row + 1, col, visited) +
				movingCountCore(threshold, rows, cols, row, col - 1, visited) +
				movingCountCore(threshold, rows, cols, row , col + 1, visited);
		}
		return count;
	}
	int getDigitSum(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
};

int main() {
	Solution s;
	cout << s.movingCount(6, 5, 5);
	system("pause");
}