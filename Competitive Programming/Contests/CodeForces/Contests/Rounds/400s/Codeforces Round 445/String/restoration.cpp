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
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
pii last[26];
string s[100005];
bool seen[26];
string merge(string a, string b, int x, int y) {

	if (y == 0){
		bool bad = false;
		FOR(i, x, a.length()) {
			if (a[i] != b[i - x]) {
				return "-1";
			}
			if (i - x == b.length() - 1) {
				return a;
			}
		}
		return a + b.substr(a.length() - x, b.length());
	}
	else if (x == 0) {
		FOR(i, y, b.length()) {
			if (b[i] != a[i - y]) {
				return "-1";
			}
			if (i - y == a.length() - 1) {
				return b;
			}
		}
		return b.substr(0, y) + a;
	}
	return "-1";
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> s[i];
		FOR(j, 0, 26) seen[j] = false;
		FOR(j, 0, s[i].length()) {
			if (seen[s[i][j] - 'a']) {
				cout << "NO" << endl;
				return 0;
			}
			seen[s[i][j] - 'a'] = true;
		}
	}
	FOR(i, 0, 26) {
		seen[i] = false;
	}
	FOR(i, 0, n) {
		int index = i;
		FOR(j, 0, s[i].length()) {
			int x = s[i][j] - 'a';
			if (seen[x]) {
				pii p = last[x];
				string str = merge(s[p.first], s[i], p.second, j);
				if (str == "-1") {
					cout << "NO" << endl;
					return 0;
				}
				s[p.first] = str;
				s[i] = "";
				index = p.first;
				FOR(k, 0, s[p.first].length()) {
					seen[s[p.first][k] - 'a'] = true;
					last[s[p.first][k] - 'a'] = { p.first, k };
				}
				break;
			}
			else {
				seen[s[i][j] - 'a'] = true;
				last[s[i][j] - 'a'] = { i, j };
			}
		}
		
	}
	FOR(i, 0, n) {
		if (s[i] == "") continue;
		int index = i;
		FOR(j, 0, s[i].length()) {
			int x = s[i][j] - 'a';
			if (seen[x]) {
				pii p = last[x];
				string str = merge(s[p.first], s[i], p.second, j);
				if (str == "-1") {
					cout << "NO" << endl;
					return 0;
				}
				s[p.first] = str;
				s[i] = "";
				index = p.first;
				FOR(k, 0, s[p.first].length()) {
					seen[s[p.first][k] - 'a'] = true;
					last[s[p.first][k] - 'a'] = { p.first, k };
				}
				break;
			}
			else {
				seen[s[i][j] - 'a'] = true;
				last[s[i][j] - 'a'] = { i, j };
			}
		}

	}
	vector<string> v;
	FOR(i, 0, n) {
		if (s[i] != "") {
			v.push_back(s[i]);
		}
	}
	string ans = "";
	sort(v.begin(), v.end());
	for (string s : v) ans += s;
	FOR(i, 0, 26) seen[i] = false;
	FOR(i, 0, ans.length()) {
		if (seen[ans[i] - 'a']) {
			cout << "NO" << endl;
			return 0;
		}
		seen[ans[i] - 'a'] = true;
	}
	cout << ans << endl;
}