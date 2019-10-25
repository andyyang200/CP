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
vector<ll> lanes;
int main()
{
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	int n, t;
	scanf("%d%d", &n, &t);
	FOR(i, 0, n)
	{
		ll p, s;
		cin >> p >> s;
		ll end = p + s * t;
		auto itr = lower_bound(lanes.begin(), lanes.end(), end);
		if (itr == lanes.begin())
		{
			lanes.insert(lanes.begin(), end);
		}
		else
		{
			*(--itr) = end;
		}
	}
	cout << lanes.size() << endl;
}