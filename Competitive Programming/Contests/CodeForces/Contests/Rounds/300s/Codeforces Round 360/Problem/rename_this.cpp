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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
vector<int> edges[100001];
int type[100001];
bool can;
void dfs(int u, int t)
{
	if (type[u] != -1)
	{
		if (type[u] != t)
		{
			can = false;
		}
		return;
	}
	if (!can)
	{
		return;
	}
	type[u] = t;
	for (int v : edges[u])
	{
		dfs(v, (t + 1) % 2);
	}
}	
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	FOR(i, 0, n)
	{
		type[i] = -1;
	}
	can = true;
	FOR(i, 0, n)
	{
		if (type[i] == -1)
		{
			dfs(i, 0);
		}
	}
	if (!can)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> a, b;
	FOR(i, 0, n)
	{
		if (type[i] == 0)
		{
			a.push_back(i);
		}
		else
		{
			b.push_back(i);
		}
	}
	cout << a.size() << endl;
	for (int x : a)
	{
		cout << x + 1 << " ";
	}
	cout << endl;
	cout << b.size() << endl;
	for (int x : b)
	{
		cout << x + 1 << " ";
	}
}