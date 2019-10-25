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
struct skill
{
	int points;
	int index;
	bool operator<(skill s)
	{
		return points > s.points;
	}
};
int n, A, cf, cm;
ll m;
skill skills[100001];
ll p[100001];
int restored[100001];
ll query(int a, int b)
{
	return p[b] - (a == 0 ? 0 : p[a - 1]);
}
int main()
{
	int n, A, cf, cm;
	ll m;
	scanf("%d%d%d%d", &n, &A, &cf, &cm);
	cin >> m;
	FOR(i, 0, n)
	{
		scanf("%d", &skills[i].points);
		skills[i].index = i;
	}
	sort(skills, skills + n);
	p[0] = skills[0].points;
	FOR(i, 1, n)
	{
		p[i] = p[i - 1] + skills[i].points;
	}
	ll ans = 0;
	int index = -1;
	int countA = 0;
	FOR(i, 0, n)
	{
		ll remaining = m;
		remaining -= (ll)(n - i) * skills[i].points - query(i, n - 1);
		if (remaining < 0)
		{
			continue;
		}
		int l = 0;
		int r = i - 1;
		int farthest = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int required = (ll)A * (mid + 1) - query(0, mid);
			if (required <= remaining)
			{
				farthest = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if ((ll)(farthest + 1) * cf + (ll)skills[i].points * cm > ans)
		{
			ans = (ll)(farthest + 1) * cf + (ll)skills[i].points * cm;
			index = i;
			countA = farthest + 1;
		}
	}
	FOR(i, 0, countA)
	{
		skills[i].points = A;
	}
	FOR(i, index, n)
	{
		skills[i].points = skills[index].points;
	}
	FOR(i, 0, n)
	{
		restored[skills[i].index] = skills[i].points;
	}
	cout << ans << endl;
	FOR(i, 0, n)
	{
		cout << restored[i] << " ";
	}
	cout << endl;	
}