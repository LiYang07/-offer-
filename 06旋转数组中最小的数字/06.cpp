#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int index1 = 0, index2 = rotateArray.size() - 1;
		int med = index1;
		while (rotateArray[index1] >= rotateArray[index2]) {
			if (index2 - index1 == 1) {
				med = index2;
				break;
			}

			int med = (index1 + index2) / 2;
			if (rotateArray[index1] == rotateArray[med] &&
				rotateArray[med] == rotateArray[index2])
				return minOrderSearch(rotateArray);
			if (rotateArray[med] >= rotateArray[index1])
				index1 = med;
			else if (rotateArray[med] <= rotateArray[index2])
				index2 = med;
		}
		return rotateArray[med];
	}
private:
	int minOrderSearch(const vector<int> &ivec) {
		int min = ivec[0];
		for (auto elem : ivec)
			if (elem <= min)
				min = elem;
		return min;

	}
};