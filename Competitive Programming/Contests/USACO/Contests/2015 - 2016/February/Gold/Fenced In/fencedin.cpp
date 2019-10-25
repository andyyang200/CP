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
typedef long long ll;
typedef pair<int, int> pii;
#define pip pair<int, pii>
#define rect pair<pii, pii>
#define F first
#define S second

vector<pii> edges;
int a[25001];
int b[25001];

int main()
{
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	int A, B, n, m;
	scanf("%d%d%d%d", &A, &B, &n, &m);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	FOR(i, 0, m)
	{
		scanf("%d", &b[i]);
	}
	sort(b, b + m);
	int p = 0;
	FOR(i, 0, n)
	{
		edges.push_back(make_pair(a[i] - p, 1));
		p = a[i];
	}
	edges.push_back(make_pair(A - a[n - 1], 1));
	p = 0;
	FOR(i, 0, m)
	{
		edges.push_back(make_pair(b[i] - p, -1));
		p = b[i];
	}
	edges.push_back(make_pair(B - b[m - 1], -1));
	sort(edges.begin(), edges.end());
	int hc = 0;
	int vc = 0;
	ll total = 0;
	for (auto& e : edges)
	{
		if (e.second > 0)
		{
			if (vc == 0)
			{
				total += (ll)m*e.first;
			}
			else
			{
				total += (hc == 0) ? (ll)m*e.first : (ll)(m - (hc - 1))*e.first;
			}
			vc++;
		}
		else
		{
			if (hc == 0)
			{
				total += (ll)(n)*e.first;
			}
			else
			{
				total += (ll)(vc == 0) ? (n)*e.first : (ll)(n - (vc - 1))*e.first;
			}
			hc++;
		}
	}
	cout << total << endl;
	return 0;
}