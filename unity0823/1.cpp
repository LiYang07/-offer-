#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>



using namespace std;

void print(vector<string>& v) {
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i] << " ";
	cout << v.back() << endl;
}

int main() {

	string str;
	getline(cin, str);
	int pos = str.find('-');
	vector<string> a, b;
	for (int start = 0, end = 0; end != string::npos && end < pos;) {
		end = str.find(" ", start);
		if (end < pos) {
			a.push_back(str.substr(start, end - start));
			start = end + 1;
		}
		else
			a.push_back(str.substr(start, pos - start));

	}
	for (int start = pos + 1, end = 0; end != string::npos;) {
		end = str.find(" ", start);
		if (end != string::npos) {
			b.push_back(str.substr(start, end - start));
			start = end + 1;
		}
		else
			b.push_back(str.substr(start, str.size() - start));
	}
	if (a.size() != b.size()) {
		if (a.size() == 2 && a[0].size() > 1)
		{
			print(a);
			return 0;
		}
		if (b.size() == 2 && b[0].size() > 1) {
			print(b);
			return 0;
		}
		if (a.size() == 4 || b.size() == 4) {
			a.size() == 4 ? print(a) : print(b);
			return 0;
		}
		cout << "ERRO" << endl;
		return 0;
	}	
	else {
		map<string, int> comp;
		for (int i = 3; i <= 10; i++) {
			comp[to_string(i)] = i;
		}
		comp["J"] = 11;
		comp["k"] = 12;
		comp["A"] = 13;
		comp["2"] = 14;
		comp["joker"] = 15;
		comp["JOKER"] = 16;
		if (a.back().size() != b.back().size()) {
			a.back().size() > 1 ? print(a) : print(b);
			return 0;
		}
		comp[a.back()] > comp[b.back()] ? print(a) : print(b);
	}
}
