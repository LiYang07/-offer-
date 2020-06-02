#include<iostream>
#include<string>

using namespace std;

int main(){
	string str;
	cin >> str;
	string upper, lower, nums, other;
	for (auto c : str) {
		if (c >= 'A'&&c <= 'Z')upper.push_back(c);
		else if (c >= 'a'&& c <= 'z') lower.push_back(c);
		else if (c >= '0' && c <= '9') nums.push_back(c);
		else other.push_back(c);
	}
	cout << upper + lower + nums + other << endl;
	return 0;
}