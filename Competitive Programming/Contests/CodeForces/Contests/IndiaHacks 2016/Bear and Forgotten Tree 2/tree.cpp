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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

set<pii> forbidden;
set<int> notVisited;
stack<int> nodes;
void dfs()
{
	while (!nodes.empty())
	{
		int node = nodes.top();
		nodes.pop();
		for (auto itr = notVisited.begin(); itr != notVisited.end();)
		{
			int nxt = *itr;
			auto f = forbidden.find({ node, nxt });
			auto f2 = forbidden.find({ nxt, node });
			if (f == forbidden.end() && f2 == forbidden.end())
			{
				notVisited.erase(itr++);
				nodes.push(nxt);
			}
			else
			{
				++itr;
			}
		}
	}
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		forbidden.insert({ a, b });
	}
	FOR(i, 1, n)
	{
		notVisited.insert(i);
	}
	nodes.push(0);
	dfs();
	if (notVisited.size() > 0)
	{
		cout << "impossible" << endl;
		return 0;
	}
	int maxDegree = n - 1;
	for (auto itr = forbidden.begin(); itr != forbidden.end(); itr++)
	{
		if (itr->first == 0 || itr->second == 0)
		{
			maxDegree--;
		}
	}
	FOR(i, 1, n)
	{
		forbidden.insert({ 0, i });
		notVisited.insert(i);
	}
	int c = 0;
	FOR(i, 1, n)
	{
		if (notVisited.find(i) != notVisited.end())
		{
			nodes.push(i);
			dfs();
			c++;
		}
	}
	if (k >= c && k <= maxDegree)
	{
		cout << "possible" << endl;
	}
	else
	{
		cout << "impossible" << endl;
	}
}