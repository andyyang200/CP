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
typedef long long ll;
typedef pair<int, int> pii;

ll dp[50000];
pii stations[50000];
int nextStation[50000];

int main()
{
	freopen("fuel.in", "r", stdin);
	freopen("fuel.out", "w", stdout);
	int n, g, b, d;
	scanf("%d%d%d%d", &n, &g, &b, &d);
	FOR(i, 0, n)
	{
		scanf("%d%d", &stations[i].first, &stations[i].second);
	}
	sort(stations, stations + n);
	stack<int> s;
	RFOR(i, n - 1, -1)
	{
		nextStation[i] = -1;
		while (!s.empty())
		{
			if (stations[s.top()].first - stations[i].first > g)
			{
				break;
			}
			if (stations[s.top()].second < stations[i].second)
			{
				nextStation[i] = s.top();
				break;
			}
			s.pop();
		}
		s.push(i);
	}
	ll cost = 0;
	b -= stations[0].first;
	FOR(i, 0, n)
	{
		if (b < 0)
		{
			cout << -1 << endl;
			return 0;
		}
		int next = min(g, (nextStation[i] == -1 ? d : stations[nextStation[i]].first) - stations[i].first);
		if (next > b) 
		{
			cost += (ll)(next - b) * (long long)stations[i].second;
			b = next;
		}
		b -= (i == n - 1 ? d : stations[i + 1].first) - stations[i].first;
	}
	if (b < 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << cost << endl;
	}
}