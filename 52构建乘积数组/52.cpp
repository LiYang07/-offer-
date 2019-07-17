//给定一个数组A[0, 1, ..., n - 1], 请构建一个数组B[0, 1, ..., n - 1], 
//其中B中的元素B[i] = A[0] * A[1] * ...*A[i - 1] * A[i + 1] * ...*A[n - 1]。不能使用除法。
#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.size() <= 1)
			return {};
		vector<int> B(A.size(),1);
		for (int i = 1; i < A.size(); i++)
			B[i]= B[i-1]*A[i-1];
		int temp = 1;
		for (int i = A.size() - 2; i >= 0; i--) {
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};

int main(){
	Solution s;
	s.multiply({ 1,2,3,4,5 });
	system("pause");
}