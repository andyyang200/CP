//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>	
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool check(string s, int n) {
	if (n > s.length()) {
		return false;
	}
	FOR(i, 0, n) {
		if (s[i] != '0') {
			return false;
		}
	}
	return true;
}
string h(string tx, string s) {
	string ss = s;
	while (ss.length() < tx.length()) {
		ss += s;
	}
	s = ss;
	string ans = "";
	FOR(i, 0, tx.length()) {
		if (tx[i] == '0') {
			ans += s[i];
		}
		else if (s[i] == '0') {
			ans += tx[i];
		}
		else {
			ans += '0' + (tx[i] - '0') % (s[i] - '0');
		}
	}
	return ans;
}
int main(void)
{
	int tx, n, s;
	cin >> tx >> n >> s;
	FOR(i, 0, 2000000) {
		string a = h(to_string(tx + i), to_string(s));
		if (check(a, n)) {
			cout << i << endl;
			return 0;
		}
	}

}