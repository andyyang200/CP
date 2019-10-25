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

vector<vector<int> > droids;
vector<int> sums;
vector<vector<int> > prefix;

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n)
	{
		vector<int> droid;
		int sum = 0;
		FOR(j, 0, m)
		{
			int x;
			scanf("%d", &x);
			sum += x;
			droid.push_back(x);
		}
		if (sum <= k || i == 0 || sums[i - 1] <= k)
		{
			droids.push_back(droid);
			sums.push_back(sum);
		}
	}
	vector<int> bestShots;
	int longest = 0;
	FOR(start, 0, droids.size())
	{
		if (sums[start] > k)
		{
			continue;
		}
		FOR(end, start + 1, droids.size() + 1)
		{
			if (end == droids.size() || sums[end] > k )
			{
				FOR(i, start, end)
				{
					RFOR(j, end - 1, i - 1)
					{
						if (j - i + 1 <= longest)
						{
							break;
						}
						vector<int> shots;
						FOR(x, 0, m)
						{
							shots.push_back(0);
						}
						FOR(x, i, j + 1)
						{
							FOR(y, 0, m)
							{
								shots[y] = max(shots[y], droids[x][y]);
							}
						}
						int sum = 0;
						FOR(x, 0, m)
						{
							sum += shots[x];
						}
						if (sum <= k)
						{
							bestShots = shots;
							longest = j - i + 1;
							break;
						}
					}
				}
				start = end + 1;
				break;
			}
		}
	}
	for (int shot : bestShots)
	{
		cout << shot << " ";
	}
	cout << endl;
}