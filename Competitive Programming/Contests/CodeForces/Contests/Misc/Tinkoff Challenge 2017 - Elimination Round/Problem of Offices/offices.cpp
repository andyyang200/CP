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

int n;
int a, b, c, d;
int p[5005];
bool to[5005][5005]; // [a][b] : is a on path to b
int targets[4];
int sz[5005];
vector<int> children[5005];
vector<int> values;
bool dp[5001];
bool knapsack(int x) {
	FOR(i, 0, x + 1) {
		dp[i] = false;
	}
	dp[0] = true;
	FOR(i, 0, values.size()) {
		RFOR(j, x, values[i] - 1) {
			if (dp[j - values[i]]) {
				dp[j] = true;
			}
		}
	}
	return dp[x];
}
void dfs(int u) {
	if (children[u].size() == 0) {
		sz[u] = 1;
	}
	FOR(i, 0, 4) {
		if (u == targets[i]) {
			to[u][targets[i]] = true;
		}
	}
	for (int v : children[u]) {
		dfs(v);
		sz[u] += sz[v];
		FOR(i, 0, 4) {
			to[u][targets[i]] |= to[v][targets[i]];
		}
	}
}
void addBranchingValues(int u, int x) {
	if (u == 0) {
		for (int v : children[u]) {
			if (to[v][x]) {
				addBranchingValues(v, x);
			}
		}
		return;
	}
	for (int v : children[u]) {
		if (to[v][x]) {
			addBranchingValues(v, x);
		}
		else {
			values.push_back(sz[v]);
		}
	}
}
int getSize(int x) // size of root son containing x
{
	for (int v : children[0]) {
		if (to[v][x]) {
			return sz[v];
		}
	}
}
bool check(int left, int right) {
	values.clear();
	for (int v : children[0]) {
		bool good = true;
		FOR(i, 0, 4) {
			if (to[v][targets[i]]) {
				good = false;
				break;
			}
		}
		if (good) {
			values.push_back(sz[v]);
		}
	}
	addBranchingValues(0, targets[left]);
	addBranchingValues(0, targets[right]);
	return knapsack((sz[0] - 2) / 2 - getSize(targets[left + 1]));
}
int main(void)
{
	scanf("%d", &n);
	scanf("%d%d%d%d", &targets[0], &targets[2], &targets[1], &targets[3]);
	targets[0]--;
	targets[1]--;
	targets[2]--;
	targets[3]--;
	p[0] = -1;
	FOR(i, 1, n) {
		scanf("%d", &p[i]);
		p[i]--;
		children[p[i]].push_back(i);
	}
	dfs(0);
	if (sz[0] % 2 == 1 || !check(0, 2) || !check(1, 3)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}