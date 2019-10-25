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
int r[1005];
int c[1005];
int help[1005][1005];
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	set<int> s;
	vector<int> v;
	FOR(i, 0, a) {
		scanf("%d", &r[i]);
		s.insert(r[i]);
	}
	for (int x : s) {
		v.push_back(x);
	}
	FOR(i, 0, a) {
		r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
	}
	int n = s.size();

	s.clear();
	v.clear();
	FOR(i, 0, b) {
		scanf("%d", &c[i]);
		s.insert(c[i]);
	}
	for (int x : s) {
		v.push_back(x);
	}
	FOR(i, 0, b) {
		c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
	}
	int m = s.size();
	if (n >= m) {
		if (ceil(log2(n)) > m) {
			cout << -1 << endl;
			return 0;
		}
		FOR(i, 0, m) {
			string s = to_string(1 << m);
			reverse(s.begin(), s.end());
			while (s.length() < m) {
				s += "0";
			}
			reverse(s.begin(), s.end());
			FOR(j, 0, m) {
				help[i][j] = s[j];
			}
		}
		int x = 0;
		FOR(i, m, n) {
			while (x > 0 && x != 1 && (x & (x - 1)) == 0) {
				x++;
			}
			string s = to_string(x);
			reverse(s.begin(), s.end());
			while (s.length() < m) {
				s += "0";
			}
			reverse(s.begin(), s.end());
			FOR(j, 0, m) {
				help[i][j] = s[j];
			}
		}
	}
	else {
		if (ceil(log2(m)) > n) {
			cout << -1 << endl;
			return 0;
		}
		FOR(i, 0, n) {
			string s = to_string(1 << n);
			reverse(s.begin(), s.end());
			while (s.length() < n) {
				s += "0";
			}
			reverse(s.begin(), s.end());
			FOR(j, 0, n) {
				help[j][i] = s[j];
			}
		}
		int x = 0;
		FOR(i, n, m) {
			while (x > 0 && x != 1 && (x & (x - 1))) {
				x++;
			}
			string s = to_string(x);
			reverse(s.begin(), s.end());
			while (s.length() < n) {
				s += "0";
			}
			reverse(s.begin(), s.end());
			FOR(j, 0, n) {
				help[j][i] = s[j];
			}
		}
	}
	FOR(i, 0, a) {
		
	}
}