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
int main()
{
	//freopen("planting.in", "r", stdin);
	//freopen("planting.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		Event start, end;
		start.x = x1;
		start.y1 = y2;
		start.y2 = y1;
		start.type = 1;
		end.x = x2;
		end.y1 = y2;
		end.y2 = y1;
		end.type = 2;
		events.push_back(start);
		events.push_back(end);
	}
	sort(events.begin(), events.end());
	int previous = -INF;
	ll ans = 0;
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
			ans += (ll)(events[i].x - previous) * totalHeights;
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
	cout << ans << endl;
}