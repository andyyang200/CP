//Andrew Yang
// accepted
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
pii a[50];
pii b[50];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	FOR(i, 0, m)
	{
		scanf("%d%d", &b[i].first, &b[i].second);
	}
	FOR(i, 0, n)
	{
		int minD = INF;
		int minI = -1;
		FOR(j, 0, m)
		{
			int d = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
			if (d < minD)
			{
				minD = d;
				minI = j;
			}
		}
		cout << minI + 1 << endl;
	}
}