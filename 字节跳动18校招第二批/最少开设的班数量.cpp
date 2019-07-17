
//最少开设班的数量
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N <= 1) {
		cout << N;
		return 0;
	}
	vector<int> nums;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int sum = N;
	for (int i = 1; i < nums.size(); i++) {
		int over = nums.back() - nums[0];
		sum  += over % nums[0] ? over / nums[0] + 1 : over / nums[0] ;
	}
	cout << sum;
	return 0;
}