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

pair<vector<int>, int> a[300005];
set<int> edges[300005];
int group[300005];
int ans[300005];
bool visited[300005];
int color[300005]; // color of a group
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		a[i].second = i;
		a[i].first.push_back(i);
	}
	FOR(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		a[u].first.push_back(v);
		a[v].first.push_back(u);
	}
	FOR(i, 0, n) {
		sort(a[i].first.begin(), a[i].first.end());
	}
	sort(a, a + n);
	int x = 1;
	group[a[0].second] = 1;
	FOR(i, 1, n) {
		if (a[i].first != a[i - 1].first) {
			x++;
		}
		group[a[i].second] = x;
	}
	FOR(i, 0, n) {
		for (int v : a[i].first) {
			if (v == a[i].second) {
				continue;
			}
			int g1 = group[a[i].second];
			int g2 = group[v];
			if (g1 != g2) {
				edges[g1].insert(g2);
				edges[g2].insert(g1);
			}
		}
	}
	bool path = false;
	int start = -1;
	FOR(i, 1, x + 1) {
		if (edges[i].size() >= 3) {
			cout << "NO" << endl;
			return 0;
		}
		if (edges[i].size() <= 1) {
			path = true;
			start = i;
		}
	}
	if (!path) {
		cout << "NO" << endl;
		return 0;
	}

	stack<int> s;
	s.push(start);
	visited[start] = true;
	int d = 1;
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		color[node] = d++;
		for (int c : edges[node]) {
			if (!visited[c]) {
				visited[c] = true;
				s.push(c);
			}
		}
	}
	FOR(i, 0, n) {
		ans[a[i].second] = color[group[a[i].second]];
	}
	cout << "YES" << endl;
	FOR(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}