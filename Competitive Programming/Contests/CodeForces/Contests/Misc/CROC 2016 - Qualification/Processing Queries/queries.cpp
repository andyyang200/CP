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
struct event
{
	ll t;
	int type; // 1- finish, 2- appear
	pii query; // index, duration
	bool operator<(const event other) const
	{
		if (t != other.t)
		{
			return t < other.t;
		}
		return type < other.type;
	}
};

ll ans[200001];
int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	set<event> events;
	FOR(i, 0, n)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		event e;
		e.t = t;
		e.query = { i, d };
		e.type = 2;
		events.insert(e);
	}
	queue<pii> q;
	bool processing = false;
	FOREACH(itr, events)
	{
		event e = *itr;
		if (e.type == 1)
		{
			ans[e.query.first] = e.t;
			processing = false;
			if (!q.empty())
			{
				event x;
				x.t = e.t + q.front().second;
				x.type = 1;
				x.query = q.front();
				q.pop();
				events.insert(x);
				processing = true;
			}
		}
		else
		{
			if (q.size() == b)
			{
				ans[e.query.first] = -1;
			}
			else
			{
				if (!processing && q.size() == 0)
				{
					event x;
					x.t = e.t + e.query.second;
					x.type = 1;
					x.query = e.query;
					events.insert(x);
					processing = true;
				}
				else
				{
					q.push(e.query);
				}
			}
		}
	}
	FOR(i, 0, n)
	{
		printf("%I64d ", ans[i]);
	}
	printf("\n");
}