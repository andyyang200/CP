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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
pii edges[100001];
vector<int> adj[100001];
int incoming[100001];
int n, m;
bool check(int x)
{
	FOR(i, 0, n)
	{
		adj[i].clear();
		incoming[i] = 0;
	}
	FOR(i, 0, x + 1)
	{
		adj[edges[i].first].push_back(edges[i].second);
		incoming[edges[i].second]++;
	}
	stack<int> s;
	FOR(i, 0, n)
	{
		if (incoming[i] == 0)
		{
			s.push(i);
		}
	}
	while (!s.empty())
	{
		if (s.size() != 1)
		{
			return 0;
		}
		int node = s.top();
		s.pop();
		FOR(i, 0, adj[node].size())
		{
			int nxt = adj[node][i];
			incoming[nxt]--;
			if (incoming[nxt] == 0)
			{
				s.push(nxt);
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		scanf("%d%d", &edges[i].first, &edges[i].second);
		edges[i].first--;
		edges[i].second--;
	}
	int l = 0;
	int r = m - 1;
	int ans = -2;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans + 1 << endl;
}