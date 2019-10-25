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
struct Event
{
	int x, h, type;
	Event(int a, int b, int c)
	{
		x = a;
		h = b;
		type = c;
	}
	bool operator<(const Event& e) const
	{
		return x < e.x;
	}
};
multiset<int> heights;
vector<Event> events;
int main()
{
	freopen("horizon.in", "r", stdin);
	freopen("horizon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int a, b, h;
		scanf("%d%d%d", &a, &b, &h);
		events.push_back(Event(a, h, 1));
		events.push_back(Event(b, h, 2));
	}
	sort(events.begin(), events.end());
	int previous = -INF;
	ll total = 0;
	FOR(i, 0, events.size())
	{
		if (heights.size() > 0)
		{
			int height = *(--heights.end());
			total += (ll)(events[i].x - previous) * height;
		}
		if (events[i].type == 1)
		{
			heights.insert(events[i].h);
		}
		else
		{
			heights.erase(heights.find(events[i].h));
		}
		previous = events[i].x;
	}
	cout << total << endl;
}