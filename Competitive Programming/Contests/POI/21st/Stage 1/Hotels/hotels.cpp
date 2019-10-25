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
#include <map>
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
vector<int> edges[5001];
vector<int> depths;
ll one[5001];
ll two[5001];
int n;
ll ans;
void dfs(int node, int p, int d) {
	depths.push_back(d);
	FOR(i, 0, edges[node].size()) {
		int j = edges[node][i];
		if (j != p) {
			dfs(j, node, d + 1);
		}
	}
}
void work(int node) {
	FOR(i, 0, edges[node].size()) {
		dfs(edges[node][i], node, 1);
		FOR(j, 0, depths.size()) {
			int distance = depths[j];
			ans += two[depths[j]];
		}
		FOR(j, 0, depths.size()) {
			two[depths[j]] += one[depths[j]];
		}
		FOR(j, 0, depths.size()) {
			one[depths[j]]++;
		}
		depths.clear();
	}
	FOR(i, 0, n) {
		one[i] = 0;
		two[i] = 0;
	}
}
int main(void)
{
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ans = 0;
	FOR(i, 0, n) {
		work(i);
	}
	cout << ans << endl;
}