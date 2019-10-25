#define _CRT_SECURE_NO_WARNINGS
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
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
vector<int> edges[1000001];
vector<pair<int, int>> b[1000001];
bool visited[1000001];
bool used[1000001];
int depth[1000001];
int p[1000001];
void dfs(int u, int d) {
	visited[u] = true;
	depth[u] = d;
	for (int v : edges[u]) {
		if (v == p[u]) continue;
		if (visited[v] && depth[v] < depth[u])
			b[depth[v]].push_back({ v, u });
		else if (!visited[v]) {
			p[v] = u;
			dfs(v, d + 1);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	p[0] = -1;
	dfs(0, 0);
	for (int d = 0; d < n; d++) {
		for (pair<int, int> e : b[d]) {
			vector<int> ans;
			int v = e.first;
			int u = e.second;
			ans.push_back(v);
			ans.push_back(u);
			while (u != v && !used[u]) {
				used[u] = true;
				u = p[u];
				ans.push_back(u);
			}
			printf("%d ", ans.size() - 1);
			for (int i = 0; i < ans.size() - 1; i++) {
				printf("%d %d ", ans[i], ans[i + 1]);
			}
			printf("\n");
		}
	}
}
/*
6 9
0 1
1 2
2 3
3 4
4 5
5 0
4 0
3 1
0 2


4 5
0 1
1 2
2 3
3 1
3 0


11 17
0 1
1 2
2 3
3 4
4 5
3 6
2 7
7 8
8 9
8 10
5 3
4 2
3 1
6 2
9 7
10 7
8 0

*/
