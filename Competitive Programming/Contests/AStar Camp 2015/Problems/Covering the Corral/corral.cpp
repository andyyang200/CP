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

struct Segment
{
	int first, second;
	bool operator< (const Segment& s) const
	{
		if (first != s.first)
		{
			return first < s.first;
		}
		return second > s.second;
	}
};
vector<Segment> segments;
vector<Segment> temp;
int best[100001][21];
int c, m;	
int getDistance(Segment a, Segment b)
{
	if (b.first < a.first)
	{
		b.first += c;
	}
	return b.first + b.second - a.first - a.second;
}
bool between(int x, int a, int b)
{
	if (a <= b)
	{
		return x >= a && x <= b;
	}
	else
	{
		return x >= a || x <= b;
	}
}
bool check(int x)
{
	x--;
	FOR(i, 0, m)
	{
		int current = i;
		int bits = log2(x) + 1;
		int distance = segments[i].second;
		FOR(j, 0, bits)
		{
			if (x & (1 << j))
			{
				int next = best[current][j];
				distance += getDistance(segments[current], segments[next]);
				current = next;
			}
			if (distance >= c)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("corral.5.in", "r", stdin);
	//freopen("corral.out", "w", stdout);
	scanf("%d%d", &c, &m);
	FOR(i, 0, m)
	{
		temp.push_back(Segment());
		scanf("%d%d", &temp[i].first, &temp[i].second);
		if (temp[i].second >= c)
		{
			cout << 1 << endl;
			return 0;
		}
	}
	sort(temp.begin(), temp.end());
	segments.push_back(temp[0]);
	FOR(i, 1, temp.size())
	{
		if (temp[i].first + temp[i].second > segments.back().first + segments.back().second)
		{
			segments.push_back(temp[i]);
		}
	}
	m = segments.size();
	FOR(i, 0, m)
	{
		int maxDistance = -1;
		best[i][0] = -1;
		for (int j = (i == 0 ? 0 : best[i - 1][0]); j % m != i || best[i][0] == -1; j++)
		{
			if (between(segments[j % m].first, segments[i].first, (segments[i].first + segments[i].second) % c))
			{
				int distance = segments[j % m].first + segments[j % m].second;
				if (segments[j % m].first < segments[i].first)
				{
					distance += c;
				}
				if (distance > maxDistance)
				{
					maxDistance = distance;
					best[i][0] = j % m;
				}
			}
			else
			{
				break;
			}
		}
	}
	FOR(i, 1, 21)
	{
		FOR(j, 0, m)
		{
			best[j][i] = best[best[j][i - 1]][i - 1];
		}
	}
	int l = 1;
	int r = m;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans << endl;
}