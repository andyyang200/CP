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
#include <map>
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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> showtimes[20];
int dp[1 << 20];
int duration[20];
int n, l;

int main()
{
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	cin >> n >> l;
	FOR(i, 0, n)
	{
		cin >> duration[i];
		int c;
		cin >> c;
		FOR(j, 0, c)
		{
			int showtime;
			cin >> showtime;
			showtimes[i].push_back(showtime);
		}
	}
	FOR(mask, 0, 1 << n)
	{
		FOR(i, 0, n)
		{
			if (!(mask & (1 << i)))
			{
				int movie = n - 1 - i;
				int showtime = upper_bound(showtimes[movie].begin(), showtimes[movie].end(), dp[mask]) - showtimes[movie].begin() - 1;
				if (showtime < 0)
				{
					continue;
				}
				dp[mask | (1 << i)] = max(dp[mask | (1 << i)], max(dp[mask], showtimes[movie][showtime] + duration[movie]));
			}
		}
	}
	int minMovies = 21;
	FOR(mask, 0, 1 << n)
	{
		if (dp[mask] >= l)
		{
			int count = 0;
			FOR(i, 0, n)
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