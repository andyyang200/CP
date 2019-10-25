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
// http://www.usaco.org/index.php?page=viewproblem2&cpid=515
















vector<int> showtimes[20];
int dp[1 << 20];
int duration[20];
int n, l;

int main()
{
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	cin >> n >> l;
	for(int i = 0; i < n; i++)
	{
		cin >> duration[i];
		int c;
		cin >> c;
		for(int j = 0; j < c; j++)
		{
			int showtime;
			cin >> showtime;
			showtimes[i].push_back(showtime);
		}
	}
	for(int mask = 0; mask < (1 << n); mask++)
	{
		for(int i = 0; i < n; i++)
		{
			if (!(mask & (1 << i)))
			{
				int showtime = upper_bound(showtimes[i].begin(), showtimes[i].end(), dp[mask]) - showtimes[i].begin() - 1;
				if (showtime >= 0)
				{
					dp[mask | (1 << i)] = max(dp[mask | (1 << i)], max(dp[mask], showtimes[i][showtime] + duration[i]));
				}
			}
		}
	}
	int minMovies = 21;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (dp[mask] >= l)
		{
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i))
				{
					count++;
				}
			}
			minMovies = min(minMovies, count);
		}
	}
	cout << (minMovies == 21 ? -1 : minMovies) << endl;
}