//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		int rows = matrix.size();
		if (rows == 0)
			return res;
		int cols = matrix[0].size();
		const int up = 0, down = 1, left = 2,right = 3;
		int row_up = 0, row_down = rows - 1, col_left = 0, col_right = cols - 1;
		
		int direction = right;
			while (row_up<=row_down && col_left<=col_right) {
				switch (direction) {
				case up:
					for (int i = row_down; i >= row_up; i--)
						res.push_back(matrix[i][col_left]);
					direction = right;
					col_left++;
					break;

				case down:
					for (int i = row_up; i <= row_down; i++)
						res.push_back(matrix[i][col_right]);
					direction = left;
					col_right--;
					break;

				case left:
					for (int i = col_right; i >= col_left; i--)
						res.push_back(matrix[row_down][i]);
					direction = up;
					row_down--;
					break;

				case right:
					for (int i = col_left; i <= col_right; i++)
						res.push_back(matrix[row_up][i]);
					direction = down;
					row_up++;
					break;
				}

			}
			return res;
	}
};

int main() {

	vector<vector<int> > vec = { {1 ,2 ,3 ,} ,{5,6,7,}, {8,9,10,},{11,12,13} };
	Solution s;
	vector<int> res = s.printMatrix(vec);
	for (auto i : res)
		cout << i << endl;
	system("pause");
}