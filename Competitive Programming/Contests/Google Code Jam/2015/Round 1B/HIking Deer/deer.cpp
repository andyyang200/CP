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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
double eps = 1e-9;
typedef long long ll;
typedef pair<int, int> pii;
int equals(double a, double b)
{
	return fabs(a - b) < eps;
}
int front(double d, vector<pair<double, double>>& hikers)
{
	int best = -1;
	FOR(i, 0, hikers.size())
	{
		if (hikers[i].first > d && best == -1)
		{
			best = i;
		}
		else if (best != -1 && (equals(hikers[best].first, hikers[i].first)) && hikers[i].second < hikers[best].second)
		{
			best = i;
		}
	}
	if (best != -1)
	{
		return best;
	}
	best = 0;
	FOR(i, 0, hikers.size())
	{
		if(equals(hikers[best].first, hikers[i].first) && hikers[i].second < hikers[best].second)
		{
			best = i;
		}
	}
	return best;
}
int back(double d, vector<pair<double, double>>& hikers)
{
	int best = -1;
	RFOR(i, hikers.size() - 1, -1)
	{
		if (hikers[i].first < d && best == -1)
		{
			best = i;
		}
		else if (best != -1 && (equals(hikers[best].first, hikers[i].first)) && hikers[i].second > hikers[best].second)
		{
			best = i;
		}
	}
	best = hikers.size() - 1;
	RFOR(i, hikers.size() - 1, -1)
	{
		if (equals(hikers[best].first, hikers[i].first) && hikers[i].second > hikers[best].second)
		{
			best = i;
		}
	}
	return best;
}
int ans;
void f(double d, int e, vector<pair<double, double>> hikers)
{
	if (e >= ans)
	{
		return;
	}
	int fr = front(d, hikers);
	int b = back(d, hikers);
	double tf, tb;
	tf = (360 - hikers[fr].first) * hikers[fr].second;
	if (hikers[b].first > hikers[fr].first)
	{
		tb = (360 - hikers[b].first + 360) * hikers[b].second;
	}
	else
	{
		tb = (360 - hikers[b].first) * hikers[b].second;
	}
	
	if (fabs(tb - tf) < eps)
	{
		ans = min(e + 1, ans);
		return;
	}
	else if (tf < tb)
	{
		ans = min(e, ans);
		return;
	}
	else if (equals(hikers[b].first, hikers[fr].first))
	{
		ans = 1;
		return;
	}
	else
	{
		f(hikers[fr].first - 0.5, e + 1, hikers);
		double dis;
		if (hikers[b].first < d)
		{
			dis = d - hikers[b].first;
		}
		else
		{
			dis = d + 360 - hikers[b].first;
		}
		dis += 0.5;
		double time = dis / hikers[b].second;
		FOR(i, 0, hikers.size())
		{
			hikers[i].first = (hikers[i].first + time * hikers[i].second);
			if (hikers[i].first >= 360)
			{
				hikers[i].first -= 360;
			}
		}
		sort(hikers.begin(), hikers.end());
		f(d, e + 1, hikers);
	}
}
int main()
{
	freopen("deer.in", "r", stdin);
	freopen("deer.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		int n;
		scanf("%d", &n);
		vector<pair<double, double>> hikers;
		FOR(i, 0, n)
		{
			int d, h, m;
			scanf("%d%d%d", &d, &h, &m);
			FOR(i, 0, h)
			{
				hikers.push_back({ d, (double)(m + i) / 360});
			}
		}
		sort(hikers.begin(), hikers.end());
		ans = hikers.size();
		f(0, 0, hikers);
		cout << "Case #" << set << ": " << ans << endl;
	}
}