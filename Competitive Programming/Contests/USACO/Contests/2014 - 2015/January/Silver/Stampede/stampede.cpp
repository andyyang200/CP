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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> events; // time, y value of cow
set<int> ray;
set<int> seen;
int main()
{
	freopen("stampede.in", "r", stdin);
	freopen("stampede.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		int x, y, r;
		cin >> x >> y >> r;
		x *= -r;
		events.push(pii(x - r, y));
		events.push(pii(x, -y));
	}
	int count = 0;
	while (!events.empty())
	{
		int time = events.top().first;
		while (!events.empty() && events.top().first == time)
		{
			if (events.top().second > 0)
			{
				ray.insert(events.top().second);
			}
			else
			{
				ray.erase(ray.find(-events.top().second));
			}
			events.pop();
		}
		if (ray.size() > 0)
		{
			seen.insert(*ray.begin());
		}
	}
	cout << seen.size() << endl;
}