/*
ID: quxiao82
PROG : rockers
LANG : C++11
*/
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
typedef long long ll;
typedef pair<int, int> pii;


const int NUM = 21;
int N, T, M;
int songTime[NUM];
int maxSong[NUM][NUM][NUM];

void Input()
{
	scanf("%d%d%d", &N, &T, &M);
	int i;
	for (i = 1; i <= N; i++)
		scanf("%d", &songTime[i]);
}

void Expand(int songNum, int diskNum, int remain)
{
	if (maxSong[songNum][diskNum][remain] == -1)
		return;
	if (songNum == N && diskNum == M)
		return;
	//   printf("(%d, %d, %d) = %d\n", songNum, diskNum, remain, maxSong[songNum][diskNum][remain]);
	int curMax = maxSong[songNum][diskNum][remain];
	if (remain >= songTime[songNum + 1])
	{
		maxSong[songNum + 1][diskNum][remain - songTime[songNum + 1]] =
			max(maxSong[songNum + 1][diskNum][remain - songTime[songNum + 1]], curMax + 1);
	}
	if (T >= songTime[songNum + 1])
	{
		maxSong[songNum + 1][diskNum + 1][T - songTime[songNum + 1]] =
			max(maxSong[songNum + 1][diskNum + 1][T - songTime[songNum + 1]], curMax + 1);
	}
	maxSong[songNum + 1][diskNum][remain] = max(maxSong[songNum + 1][diskNum][remain], curMax);
}

void Solve()
{
	int i, j, k, ans;
	ans = -1;
	memset(maxSong, -1, sizeof(maxSong));
	//   for (i = 0; i <= T; i ++)
	//   {
	//         maxSong[0][0][i] = 0;
	//   }
	maxSong[0][0][0] = 0;
	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= N; j++)
		{
			for (k = 0; k <= T; k++)
			{
				Expand(j, i, k);
			}
		}
	}

	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= N; j++)
		{
			for (k = 0; k <= T; k++)
			{
				if (maxSong[j][i][k] > ans)
				{
					//                         printf("max: (%d, %d, %d) = %d\n", j, i, k, maxSong[j][i][k]);
					ans = maxSong[j][i][k];
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	Input();
	Solve();

	return 0;
}