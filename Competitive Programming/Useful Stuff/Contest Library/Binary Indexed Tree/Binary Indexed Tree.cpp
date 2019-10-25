
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

set<int> no[200005];
set<int> visit;
int sz;
int n, m;
void dfs(int x) {
	visit.erase(visit.find(x));
	sz++;
	for (int y : visit) {
		if (no[x].find(y) == no[x].end()) {
			dfs(y);
			break;
		}
	}
}
int main() {
	cin >> n >> m;
	FOR(i, 0, n) {
		visit.insert(n);
	}
	FOR(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		no[x].insert(y);
		no[y].insert(x);
	}
	vector<int> ans;
	FOR(i, 0, n) {
		if (visit.find(i) != visit.end()) {
			sz = 0;
			dfs(i);
			ans.push_back(sz);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans)cout << x << " ";
	cout << endl;

}

