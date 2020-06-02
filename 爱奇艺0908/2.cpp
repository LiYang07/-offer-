#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>;

using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	queue<pair< pair<int, int>, double>> q;
	double res = 0.0;
	q.push(make_pair(make_pair(n, m), 1.0));
	while (!q.empty()) {
		auto elem = q.front();
		q.pop();
		int r = elem.first.first;
		int b = elem.first.second;
		int s = r + b;
		double p = elem.second;
		if (b == 0)
			res += p;
		else if(r>0)
			res += p*(r*1.0 / (r + b));//±æ¬÷ªÒ §∏≈¬ 
		if (r > 0 && b >= 3) { //±æ¬÷∂º≥ÈµΩ¿∫«Ú
			double newp = b*(b - 1)*(b - 2)*p / (s*(s - 1)*(s - 2));
			q.push(make_pair(make_pair(r, b - 3), newp));
		}
		if (r > 0 && b >= 2) { //A,B≥ÈµΩ¿∫«Ú£¨C≥ÈµΩ∫Ï«Ú
			double newp = b*(b-1)*(r-1)*p/ (s*(s - 1)*(s - 2));
			q.push(make_pair(make_pair(r-1, b - 2), newp));
		}
	}
	cout << res << endl;
	return 0;
}