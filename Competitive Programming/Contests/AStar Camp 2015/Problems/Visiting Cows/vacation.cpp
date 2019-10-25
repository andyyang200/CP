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
int dp[50001][2];
vector<int> edges[50001];
int visited[100001];
int f(int node, int parent, int used)
{
	if (dp[node][used] != -1)
	{
		return dp[node][used];
	}
	int total = used;
	FOR(i, 0, edges[node].size())
	{
		if (edges[node][i] == parent)
		{
			continue;
		}
		if (used)
		{
			total += f(edges[node][i], node, 0);
		}
		else
		{
			total += max(f(edges[node][i], node, 0), f(edges[node][i], node, 1));
		}
	}
	return dp[node][used] = total;
}
int main()
{
	freopen("vacation.in", "r", stdin);
	freopen("vacation.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n - 1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	FOR(i, 0, n)
	{
		dp[i][0] = dp[i][1] = -1;
	}
	cout << max(f(0, -1, 0), f(0, -1, 1)) << endl;
}