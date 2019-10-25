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
int likes[1000001];
int last[1000001];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int like;
		scanf("%d", &like);
		likes[like]++;
		last[like] = i;
	}
	int maxLikes = 0;
	int best = -1;
	FOR(i, 0, 1000001)
	{
		if (likes[i] > maxLikes)
		{
			best = i;
			maxLikes = likes[i];
		}
		else if (likes[i] == maxLikes && last[i] < last[best])
		{
			best = i;
		}
	}
	cout << best << endl;
}