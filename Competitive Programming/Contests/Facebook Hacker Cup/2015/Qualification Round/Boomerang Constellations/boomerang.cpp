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
typedef pair<int, int> pii;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
pii points[2001];
int getDistance(pii a, pii b)
{
	int x = abs(b.first - a.first);
	int y = abs(b.second - a.second);
	return x * x + y * y;
}
int main()
{
	int sets;
	cin >> sets;
	FOR(set, 0, sets)
	{
		int n;
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> points[i].first >> points[i].second;
		}
		int ans = 0;
		FOR(i, 0, n)
		{
			std::set<int> s;
			FOR(j, 0, n)
			{
				s.insert(getDistance(points[i], points[j]));
			}
			vector<int> distances;
			FOREACH(itr, s)
			{
				distances.push_back(*itr);
			}
			map<int, int> m;
			FOR(j, 0, n)
			{
				int d = getDistance(points[i], points[j]);
				m[*lower_bound(distances.begin(), distances.end(), d)]++;
			}
			FOREACH(itr, m)
			{
				int x = itr->second;
				ans += x * (x - 1) / 2;
			}
		}
		cout << "Case #" << set + 1 << ": " << ans << endl;
	}
}