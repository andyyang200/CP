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
bool reach[1001][1001];
vector<int> edges[1001];
bool visited[1001];
void dfs(int start, int node)
{
	if (visited[node])
	{
		return;
	}
	reach[start][node] = true;
	reach[node][start] = true;
	visited[node] = true;
	FOR(i, 0, edges[node].size())
	{
		dfs(start, edges[node][i]);
	}
}
int main()
{
	freopen("ranking.in", "r", stdin);
	freopen("ranking.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
	}
	FOR(i, 0, n)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			if (!reach[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}