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
int p[100005];
vector<int> children[100005];
int last[100005];
int l[100005];
int r[100005];
int sz[100005];
int t;
void dfs(int node) {
	l[node] = t++;
	sz[node] = 1;
	for (int c : children[node]) {
		dfs(c);
		sz[node] += sz[c];
	}
	r[node] = t++;
}
int main(void)
{
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	FOR(i, 0, m) {
		last[i] = -1;
	}
	FOR(i, 0, k) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		p[a] = last[b];
		if (p[a] != -1) {
			children[p[a]].push_back(a);
		}
		last[b] = a;
	}
	t = 0;
	FOR(i, 0, n) {
		if (p[i] == -1) {
			dfs(i);
		}
	}
	FOR(i, 0, q) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if (last[y] == -1) {
			cout << 0 << endl;
			continue;
		}
		int j = last[y];
		if (l[j] > l[x] && r[j] < r[x]) {
			cout << sz[x] << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}