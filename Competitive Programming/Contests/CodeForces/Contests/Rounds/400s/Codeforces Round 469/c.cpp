//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	set<int> ones;
	set<int> zeroes;
	FOR(i, 0, n) {
		if (s[i] == '1') {
			ones.insert(i);
		}
		else {
			zeroes.insert(i);
		}
	}
	vector<vector<int>> ans;
	while (!ones.empty()) {
		if (zeroes.empty()) {
			cout << -1 << endl;
			return 0;
		}
		if (*zeroes.begin() > *ones.begin()) {
			cout << -1 << endl;
			return 0;
		}
		vector<int> v;
		v.push_back(*zeroes.begin());
		int pos = *zeroes.begin();
		zeroes.erase(zeroes.begin());
		while (true) {
			auto o = ones.upper_bound(pos);
			if (o == ones.end()) break;
			pos = *o;
			auto z = zeroes.upper_bound(pos);
			if (z == zeroes.end()) break;
			pos = *z;
			v.push_back(*o);
			v.push_back(*z);
			ones.erase(o);
			zeroes.erase(z);
		}
		if (v.size() == 1) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(v);
	}
	FOREACH(itr, zeroes) {
		vector<int> v;
		v.push_back(*itr);
		ans.push_back(v);
	}
	cout << ans.size() << endl;
	FOREACH(itr1, ans) {
		cout << itr1->size();
		FOREACH(itr2, (*itr1)) {
			cout << " " << *itr2 + 1;
		}
		cout << endl;
	}
}
