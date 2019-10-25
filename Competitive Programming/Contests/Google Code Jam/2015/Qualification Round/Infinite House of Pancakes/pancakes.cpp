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
vector<int> plates;
int main()
{
	freopen("pancakes.in", "r", stdin);
	freopen("pancakes.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		plates.clear();
		int d;
		scanf("%d", &d);
		FOR(i, 0, d)
		{
			int p;
			scanf("%d", &p);
			plates.push_back(p);
		}
		int minTime = INF;
		FOR(i, 1, 1000)
		{
			int time = 0;
			vector<int> temp = plates;
			FOR(j, 0, temp.size())
			{
				if (temp[j] > i)
				{
					temp.push_back(temp[j] - i);
					time++;
				}
			}
			time += i;
			minTime = min(minTime, time);
		}
		cout << "Case #" << test + 1 << ": " << minTime << endl;
	}
}