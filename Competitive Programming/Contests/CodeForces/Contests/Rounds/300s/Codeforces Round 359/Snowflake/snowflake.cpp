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
int p[300005];
vector<int> edges[300005];
int s[300005];
int maxSize[300005];
int centroid[300005];
void getSize(int u)
{
	s[u]++;
	for (int v : edges[u])
	{
		getSize(v);
		s[u] += s[v];
		maxSize[u] = max(maxSize[u], s[v]);
	}
}
void getCentroid(int u)
{
	if (edges[u].size() == 0)
	{
		centroid[u] = u;
		return;
	}
	for (int v : edges[u])
	{
		getCentroid(v);
	}
	if (maxSize[u] * 2 <= s[u])
	{
		centroid[u] = u;
		return;
	}
	for (int v : edges[u])
	{
		int c = centroid[v];
		while (c != u)
		{
			if (maxSize[c] * 2 <= s[u] && (s[u] - s[c]) * 2 <= s[u])
			{
				centroid[u] = c;
				return;
			}
			if (maxSize[c] * 2 > s[u])
			{
				break;
			}
			c = p[c];
		}
	}
}
int main(void)
{
	int n, q;
	scanf("%d%d", &n, &q);
	p[0] = -1;
	FOR(i, 1, n)
	{
		scanf("%d", &p[i]);
		p[i]--;
		edges[p[i]].push_back(i);
	}
	getSize(0);
	getCentroid(0);
	FOR(i, 0, q)
	{
		int a;
		scanf("%d", &a);
		cout << centroid[a - 1] + 1 << endl;
	}
}