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
using namespace std;

#define int long long
#define pii pair<int,int>

const int MaxN = 1E5 + 10;
pii p[MaxN];
map <pii, int> mp;

 main()
 {
	int n;
	cin >> n;
	for (int i = 0; i<n; ++i)
	{
		cin >> p[i].first >> p[i].second;
		mp[p[i]] = i + 1;
	}
	sort(p, p + n);
	int ind = 2;
	while ((p[0].second - p[1].second)*(p[0].first - p[ind].first) == (p[0].first - p[1].first)*(p[0].second - p[ind].second))
		++ind;
	cout << mp[p[0]] << " " << mp[p[1]] << " " << mp[p[ind]];
}