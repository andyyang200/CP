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
map<int, int> m;
map<int, int> p;
int main(void)
{
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	FOR(i, 0, n)
	{
		int a;
		scanf("%d", &a);
		m[a]++;
	}
	m[-INF] = 0;
	m[-INF+1] = 0;
	m[INF] = 0;
	int sum = 0;
	FOREACH(itr, m)
	{
		sum += itr->second;
		p[itr->first] += sum;
	}
	FOR(i, 0, q)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		auto x = --p.upper_bound(b);
		if (x->first < a)
		{
			cout << 0 << endl;
			continue;
		}
		auto y = --p.upper_bound(a);
		while (y->first >= a)
		{
			y--;
		}
		cout << x->second - y->second << endl;
	}
}