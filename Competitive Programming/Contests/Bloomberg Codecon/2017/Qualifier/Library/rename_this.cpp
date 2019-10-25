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
map<string, set<string>> m;
map<string, bool> done;
map<string, bool> in;
void dfs(string s) {
	in[s] = true;
	for (string t : m[s]) {
		dfs(t);
	}
}
int main(void)
{
	string target;
	cin >> target;
	int n;
	cin >> n;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		int j;
		cin >> j;
		m[s] = set<string>();
		FOR(x, 0, j) {
			string d;
			cin >> d;
			m[s].insert(d);
		}
	}
	dfs(target);
	while (true) {
		bool bad = false;
		FOREACH(itr2, m[target]) {
			if (!done[*itr2]) {
				bad = true;
				break;
			}
		}
		if (!bad) {
			cout << target << endl;
			return 0;
		}
		set<string> s;
		FOREACH(itr, m) {
			if (!in[itr->first]) continue;
			if (done[itr->first]) continue;
			bool bad = false;
			FOREACH(itr2, itr->second) {
				if (!done[*itr2]) {
					bad = true;
					break;
				}
			}
			if (!bad) {
				cout << itr->first << " ";
				s.insert(itr -> first);
			}
		}
		for (string str : s) {
			done[str] = true;
		}
	}
}