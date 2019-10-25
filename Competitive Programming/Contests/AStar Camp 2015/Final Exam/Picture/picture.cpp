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
multiset<pii> sections;
vector<pii> merged;
struct Event
{
	int x, y1, y2, type; // type 1: start, type 2: end
	bool operator<(const Event& e) const
	{
		return x < e.x;
	}
};
vector<Event> events;
vector<Event> events2;
int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		Event start, end;
		start.x = x1;
		start.y2 = y2;
		start.y1 = y1;
		start.type = 1;
		end.x = x2;
		end.y2 = y2;
		end.y1 = y1;
		end.type = 2;
		events.push_back(start);
		events.push_back(end);
		start.x = y1;
		start.y2 = x2;
		start.y1 = x1;
		start.type = 1;
		end.x = y2;
		end.y2 = x2;
		end.y1 = x1;
		end.type = 2;
		events2.push_back(start);
		events2.push_back(end);
	}
	ll ans = 0;
	sort(events.begin(), events.end());
	int previous = -INF;
	FOR(i, 0, events.size())
	{
		if (i > 0)
		{
			merged.clear();
			for (multiset<pii>::iterator it = sections.begin(); it != sections.end(); it++)
			{
				merged.push_back(*it);
				if (merged.size() > 1 && merged.back().first <= merged[merged.size() - 2].second)
				{
					merged[merged.size() - 2].second = max(merged[merged.size() - 2].second, merged.back().second);
					merged.pop_back();
				}
			}
			int totalHeights = 0;
			FOR(j, 0, merged.size())
			{
				totalHeights += merged[j].second - merged[j].first;
			}
			ans += (ll)(events[i].x - previous) * 2 * merged.size();
		}
		if (events[i].type == 1)
		{
			sections.insert(make_pair(events[i].y1, events[i].y2));
		}
		else
		{
			sections.erase(sections.find(make_pair(events[i].y1, events[i].y2)));
		}
		previous = events[i].x;
	}
	sections.clear();
	sort(events2.begin(), events2.end());
	previous = -INF;
	FOR(i, 0, events2.size())
	{
		if (i > 0)
		{
			merged.clear();
			for (multiset<pii>::iterator it = sections.begin(); it != sections.end(); it++)
			{
				merged.push_back(*it);
				if (merged.size() > 1 && merged.back().first <= merged[merged.size() - 2].second)
				{
					merged[merged.size() - 2].second = max(merged[merged.size() - 2].second, merged.back().second);
					merged.pop_back();
				}
			}
			int totalHeights = 0;
			FOR(j, 0, merged.size())
			{
				totalHeights += merged[j].second - merged[j].first;
			}
			ans += (ll)(events2[i].x - previous) * 2 * merged.size();
		}
		if (events2[i].type == 1)
		{
			sections.insert(make_pair(events2[i].y1, events2[i].y2));
		}
		else
		{
			sections.erase(sections.find(make_pair(events2[i].y1, events2[i].y2)));
		}
		previous = events2[i].x;
	}
	cout << ans << endl;
}