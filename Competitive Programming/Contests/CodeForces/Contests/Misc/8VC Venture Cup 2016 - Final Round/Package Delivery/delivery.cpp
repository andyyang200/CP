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
pii stations[200001];
int nxt[200001];
int main()
{
	int d, n, m;
	scanf("%d%d%d", &d, &n, &m);
	FOR(i, 0, m)
	{
		scanf("%d%d", &stations[i].first, &stations[i].second);
	}
	sort(stations, stations + m);
	stack<int> s;
	RFOR(i, m - 1, -1)
	{
		nxt[i] = -1;
		while (!s.empty())
		{
			if (stations[s.top()].second > stations[i].second)
			{
				s.pop();
			}
			else
			{
				nxt[i] = s.top();
				break;
			}
		}
		s.push(i);
	}
	ll cost = 0;
	int gas = n;
	FOR(i, 0, m)
	{
		gas -= stations[i].first - (i == 0 ? 0 : stations[i - 1].first);
		if (gas < 0)
		{
			cout << -1 << endl;
			return 0;
		}
		int needed;
		if (nxt[i] == -1 || stations[nxt[i]].first - stations[i].first > n)
		{
			needed = min(n, d - stations[i].first);
		}
		else
		{
			needed = stations[nxt[i]].first - stations[i].first;
		}
		if (gas < needed)
		{
			cost += (ll)stations[i].second * (needed - gas);
			gas = needed;
		}
	}
	gas -= d - stations[m - 1].first;
	if (gas < 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << cost << endl;
	}
}