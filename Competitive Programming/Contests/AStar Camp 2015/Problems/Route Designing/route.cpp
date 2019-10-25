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
typedef long long ll;
typedef pair<int, int> pii;

struct Data
{
	int a, b, c;
	Data(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;
	}
	bool operator<(const Data& d) const
	{
		if (a != d.a)
		{
			return a < d.a;
		}
		if (b != d.b)
		{
			return b < d.b;
		}
		return c < d.c;
	}
};
map<Data, ll> memo;
vector<int> lRoutes[40005];
vector<int> rRoutes[40005];
int lValues[40005];
int rValues[40005];

int N, M, R;
ll dp(int previous, int current, int currentSide)
{
	map<Data, ll>::iterator itr = memo.find(Data(previous, current, currentSide));
	if (itr != memo.end())
	{
		return itr->second;
	}
	ll best = 0;
	int nextSide = (currentSide + 1) % 2;
	FOR (i, 0, (currentSide == 0 ? lRoutes[current].size() : rRoutes[current].size()))
	{
		int next = (currentSide == 0 ? lRoutes[current] : rRoutes[current])[i];
		if (next > previous)
		{
			best = max(best, dp(current, next, nextSide));
		}
	}
	best += (currentSide == 0 ? lValues[current] : rValues[current]);
	memo[Data(previous, current, currentSide)] = best;
	return best;
}

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	scanf("%d%d%d", &N, &M, &R);
	FOR(i, 0, N)
	{
		scanf("%d", &lValues[i]);
	}
	FOR(i, 0, M)
	{
		scanf("%d", &rValues[i]);
	}
	FOR(i, 0, R)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		lRoutes[l].push_back(r);
		rRoutes[r].push_back(l);
	}
	ll best = 0;
	FOR(i, 0, N)
	{
		best = max(best, dp(-1, i, 0));
	}
	FOR(i, 0, M)
	{
		best = max(best, dp(-1, i, 1));
	}
	cout << best << endl;
}