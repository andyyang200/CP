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
double dis[10001];
pair<pii, double>  edges[25001];
int main()
{
	freopen("bigmac.in", "r", stdin);
	freopen("bigmac.out", "w", stdout);
	ll n, m, a, b;
	double v;
	cin >> n >> m >> v >> a >> b;
	a--;
	b--;
	FOR(i, 0, m)
	{
		int u, v;
		double e;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		cin >> e;
		edges[i] = make_pair(pii(u, v), log10(e));
	}
	FOR(i, 0, n)
	{
		dis[i] = (double)INF * INF;
	}
	dis[a] = 0;
	FOR(i, 1, n)		
	{	
		FOR(j, 0, m)
		{
			if (dis[edges[j].first.first] + edges[j].second < dis[edges[j].first.second])
			{
				dis[edges[j].first.second] = dis[edges[j].first.first] + edges[j].second;
			}
		}
	}
	FOR(j, 0, m)
	{
		if (dis[edges[j].first.first] + edges[j].second < dis[edges[j].first.second] - 1e-7)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	double cost = v * pow(10, dis[b]);
	cout << (ll)(cost + 1e-7) << endl;
}