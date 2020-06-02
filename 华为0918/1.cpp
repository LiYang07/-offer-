#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<sstream>

using namespace std;



int main() {
	string line;
	
	while (getline(cin, line))
	{
		int t;
		vector<int> a;
		stringstream data(line);
		while (data >> t)
		{
			if (t >= 10)
				a.push_back(1);
			else
				a.push_back(0);
		}
		int  j = 1;
		for (; j < a.size(); j++) {
			if (a[j] == a[j - 1]) break;
		}
		if (j == a.size())
			cout << "true" <<" ";
		else {
			if (a.front() != a.back()) //首尾元素不同
				cout << "false" <<" ";
			else {
				int sum = accumulate(a.begin() + 1, a.end() - 1, 0);
				if (sum == 0 && a[0] == 1 || sum == a.size() - 2 && a.back() == 0)
					cout << "true" <<" ";
				else
					cout << "false" <<" ";
			}

		}
	}
	return 0;
}