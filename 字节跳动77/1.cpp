#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//此题先保证能A队能赢的最多，再保证能平的最多，最后就是输的组数
int main() {
	int N;
	scanf("%d", &N);
	if (N == 0) {
		printf("%d", 0);
		return 0;
	}
	int *a = new int[N], *b = new int[N];
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	sort(&a[0], &a[N]);
	sort(&b[0], &b[N]);
	int pos1 = 0, pos2 = pos1;
	int wins = 0, draws= 0;//赢的数量，平的数量
	while (pos1 < N && pos2<N) {
		if (a[pos1] > b[pos2]) {
			++wins;
			a[pos1++] = -1; 
			b[pos2++] = -1;
		}
		else{
			++pos1;
		}
	}
	if (pos2 >N ) {
		printf("%d", N);
		return 0;
	}
	pos1 = 0;
	while (pos1 < N&&pos2 < N) {
		while (pos1 < N&&a[pos1] == -1)++pos1;
		if (pos1 < N&&pos2 < N&&a[pos1] == b[pos2]) {
			++draws;
			++pos1;
			++pos2;
		}
		else
			++pos1;
	}
	int res = wins - (N - wins - draws);
	printf("%d", res);
	delete[] a;
	delete[] b;
	return 0;
}