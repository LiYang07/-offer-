#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
			return false;
		bool *visted = new bool[cols*rows];
		memset(visted, 0, rows*cols);
		int pathLength = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				if (hasPathCore(matrix, rows, cols, i, j, str, pathLength,visted))
					return true;
		}
		delete[] visted;
		return false;
	}
	bool hasPathCore(char*matrix, int rows, int cols, int row, int col, char* str, int&pathLength,bool*visted) {
		if (str[pathLength] == '\0')
			return true;
		bool hasPath = false;
		if (row >= 0 && row < rows&&col >= 0 && col <= cols && matrix[row*cols + col] == str[pathLength] && !visted[row*cols + col]) {
			pathLength++;//遍历下一个字符
			visted[row*cols + col] = true;//这个点已经访问过了
			hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visted) ||
				hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visted) ||
				hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visted) ||
				hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visted);

			if (!hasPath) {
				--pathLength;
				visted[row*cols + col] = false;
			}
		}
		
		return hasPath;
	}
};
int main(){
	char* matrix = const_cast<char*>("abcesfcsadee");
	Solution s;
	char c[5] = { 'b','c','c','e','\0' };
	cout << s.hasPath(matrix, 3, 4, c);
	system("pause");
}