#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[4][4];
void up_remove() {
	int i, j, k;
	for (j = 0; j < 4; j++) {
		for (i = 1; i < 4; i++) {
			k = i;
			while (k - 1 >= 0 && a[k - 1][j] == 0) {
				swap(a[k][j], a[k - 1][j]);
				k--;

			}
		}
	}
}
void down_remove() {
	int i, j, k;
	for (j = 0; j < 4; j++) {
		for (i = 2; i >= 0; i--) {
			k = i;
			while (k + 1 <= 3 && a[k + 1][j] == 0) {
				swap(a[k][j], a[k + 1][j]);
				k++;
			}
		}
	}
}
void left_remove() {
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			k = j;
			while (k - 1 >= 0 && a[i][k - 1] == 0) {
				swap(a[i][k], a[i][k - 1]);
				k--;
			}
		}
	}
}
void right_remove(){
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 2; j >= 0; j--) {
			k = j;
			while (k + 1 <= 3 && a[i][k + 1] == 0) {
				swap(a[i][k], a[i][k + 1]);
				k++;
			}
		}
	}
}
void left() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			if (a[i][j] == a[i][j + 1]) {
				a[i][j] += a[i][j + 1];
				a[i][j + 1] = 0;
				left_remove();
			}
		}
	}
}
void right() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 3; j >= 1; j--) {
			if (a[i][j] == a[i][j - 1]) {
				a[i][j] += a[i][j - 1];
				a[i][j - 1] = 0;
				right_remove();
			}
		}
	}
}
void up() {
	int i, j;
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 3; i++) {
			if (a[i][j] == a[i + 1][j]) {
				a[i][j] = a[i][j] + a[i + 1][j];
				a[i + 1][j] = 0;
				up_remove();
			}
		}
	}
}
void down() {
	int i, j;
	for (j = 0; j < 4; j++) {//每一列 
		for (i = 3; i >= 1; i--) {
			if (a[i][j] == a[i - 1][j]) {
				a[i][j] = a[i][j] + a[i - 1][j];
				a[i - 1][j] = 0;
				down_remove();
			}
		}
	}
}

int main() {
	int i, j,n;
	cin >> n;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cin >> a[i][j];
			}
		}
		if (n == 1) {//上
			up_remove();
			up();

		}
		else if (n == 2) {//下 
			down_remove();
			down();
		}
		else if (n == 3) {//左
			left_remove;
			left();
		}
		else {//右
			right_remove();
			right();
		}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 3) cout<<a[i][j]<<" "<<endl;
			else cout<<a[i][j];
		}
	}
	system("pause");
	return 0;
}
