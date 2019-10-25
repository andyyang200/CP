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
int p[100005][20];
int depth[100005];
vector<int> edges[100005];
int n;
void dfs(int node) {
	for (int v : edges[node]) {
		if (v == p[node][0]) {
			continue;
		}
		p[v][0] = node;
		depth[v] = depth[node] + 1;
		dfs(v);
	}
}
void prep() {
	for (int j = 1; j < 18; ++j) {
		for (int i = 0; i < n; ++i) {
			if (p[i][j - 1] == -1) {
				p[i][j] = -1;
			}
			else {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
}
int getLCA(int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	for (int k = 17; k >= 0; --k) {
		if (depth[a] - (1 << k) >= depth[b]) {
			a = p[a][k];
		}
	}
	if (a == b) {
		return a;
	}
	for (int k = 16; k >= 0; k--) {
		if (p[a][k] != p[b][k]) {
			a = p[a][k];
			b = p[b][k];
		}
	}
	return p[a][0];
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	p[0][0] = -1;
	dfs(0);
	prep();
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) { 
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", getLCA(a, b));
	}
}