//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	int rows, cols,t;
//	cin >> rows >> cols;
//	vector<vector<int> > matrix(rows, vector<int>(cols));
//	for(int i=0;i<rows;i++)
//		for (int j = 0; j < cols; j++) {
//			cin >> t;
//			matrix[i][j] = t;
//		}
//	vector<int> res;
//	const int up = 0, down = 1, left = 2, right = 3;
//	int row_up = 0, row_down = rows - 1, col_left = 0, col_right = cols - 1;
//
//	int direction = down;
//	while (row_up <= row_down && col_left <= col_right) {
//		switch (direction) {
//		case down:
//			for (int i = row_up; i <= row_down; i++)
//				res.push_back(matrix[i][col_left]);
//			direction = right;
//			col_left++;
//			break;
//
//		case up:
//			for (int i = row_down; i >= row_up; i--)
//				res.push_back(matrix[i][col_right]);
//			direction = left;
//			col_right--;
//			break;
//
//
//		case left:
//			for (int i = col_right; i >= col_left; i--)
//				res.push_back(matrix[row_up][i]);
//			direction = down;
//			row_up++;
//			break;
//
//		case right:
//			for (int i = col_left; i <= col_right; i++)
//				res.push_back(matrix[row_down][i]);
//			direction = up;
//			row_down--;
//			break;
//		}
//
//	}
//	for (auto i : res)
//		cout << i << " ";
//	return 0;
//}
