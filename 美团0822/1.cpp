#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <fstream>

using namespace std;

int main() {
	string str;
	cin >> str;
	vector<vector<int> >  hash;
	
	for (int i = 0; i < 26; i++) {
		hash.push_back(vector<int>(2, -1));
	}
	for (int i = 0; i < 26; i++) {
		size_t pos = str.find_first_of('A' + i);
		if (pos != string::npos) {
			hash[i][0] = pos;
			hash[i][1] = str.find_last_of('A' + i);
		}
	}
	vector<int> res;
	for (int i = 0; i < str.size(); i++) {
		if (hash[str[i] - 'A'][0] == hash[str[i] - 'A'][1]) {
			res.push_back(1);
			continue;
		}
		int curlastpos = hash[str[i] - 'A'][1];
		for (int j = i + 1; j <= curlastpos ; j++)
		{
			if (hash[str[j]-'A'][1] > curlastpos)
				curlastpos = hash[str[j]-'A'][1];
		}
		res.push_back(curlastpos - i + 1);
		i = curlastpos ;
	}
	for (auto i : res) {
		cout << i << endl;
	return 0;
}