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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> edges[100001];
int nodes[100001];
ll dfs(int node, ll t)
{
	ll total = nodes[node];
	FOR(i, 0, edges[node].size())
	{
		total += min(dfs(edges[node][i].second, t), t * edges[node][i].first);
	}
	return total;
}
int main()
{
	freopen("bottleneck.in", "r", stdin);
	freopen("bottleneck.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
		int p, c, m;
		scanf("%d%d%d", &p, &c, &m);
		p--;
		nodes[i] = c;
		edges[p].push_back(pii(m, i));
	}
	
	FOR(i, 0, k)
	{
		int t;
		scanf("%d", &t);
		cout << dfs(0, t) << "\n";
	}
}