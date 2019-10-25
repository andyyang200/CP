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
char grid[501][501];
int p[200001];
int d[200001];
int cnt[200001];
int findSet(int i)
{
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	if (!isSameSet(i, j))
	{
		int x = findSet(i);
		int y = findSet(j);
		if (d[x] > d[y])
		{
			p[y] = x;
			cnt[x] += cnt[y];
		}
		else
		{
			p[x] = y;
			cnt[y] += cnt[x];
			if (d[x] == d[y])
				d[y]++;
		}
	}
}
int main(void)
{
	int n, k;
	cin >> n >> k;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cin >> grid[i][j];
		}
	}
}