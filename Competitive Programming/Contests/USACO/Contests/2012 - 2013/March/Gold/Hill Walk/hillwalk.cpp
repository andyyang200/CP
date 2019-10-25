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
int x, y;
struct Event
{
	int x, y, type;
	Event(int a, int b, int c)
	{
		x = a;
		y = b;
		type = c;
	}
	bool operator<(const Event& e) const
	{
		return pii(x, y) < pii(e.x, e.y);
	}
};
struct Hill
{
	int x1, y1, x2, y2;
	Hill(int a, int b, int c, int d)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	bool operator<(const Hill& s) const
	{
		double m1 = ((double)y2 - y1) / (x2 - x1);
		double b1 = y1 - m1 * x1;
		double m2 = ((double)s.y2 - s.y1) / (s.x2 - s.x1);
		double b2 = s.y1 - m2 * s.x1;
		return x * m1 + b1 < x * m2 + b2;
	}
};
vector<Event> events;
map<pii, pii> s;
map<pii, pii> e;
set<Hill> hills;
int main()
{
	freopen("hillwalk.in", "r", stdin);
	freopen("hillwalk.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		e[pii(x1, y1)] = pii(x2, y2);
		s[pii(x2, y2)] = pii(x1, y1);
		events.push_back(Event(x1, y1, 1));
		events.push_back(Event(x2, y2, 2));
	}
	sort(events.begin(), events.end());
	int count = 1;
	x = y = 0;
	Hill current = Hill(0, 0, e[{0, 0}].first, e[{0, 0}].second);
	FOR(i, 1, events.size())
	{
		if (events[i].type == 1)
		{
			x = events[i].x;
			y = events[i].y;
			int x2 = e[{x, y}].first;
			int y2 = e[{x, y}].second;
			if (Hill(x, y, x2, y2) < current)
			{
				hills.insert(Hill(x, y, x2, y2));
			}
		}
		else
		{
			int x = events[i].x;
			int y = events[i].y;
			if (x == current.x2 && y == current.y2)
			{
				if (hills.size() == 0)
				{
					break;
				}
				else
				{
					current = *(--hills.end());
					hills.erase(--hills.end());
					count++;
				}
			}
			int x1 = s[{x, y}].first;
			int y1 = s[{x, y}].second;
			if (Hill(x1, y1, x, y) < current)
			{
				hills.erase(Hill(x1, y1, x, y));
			}
		}
	}
	cout << count << endl;
}