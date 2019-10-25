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
/* You have N flowers in a row. The ith flower has height ai.
For d days, you water a segment of w consecutive flowers, increasing
each of their heights by 1. The "score" of the row of flowers is the minimum
height of a flower in the row. What is the maximum possible score?
*/














int n, m, w, flowers[100001], segments[100001];
bool check(int middle)
{
	FOR(i, 0, n)
	{
		segments[i] = 0;
	}
	int moves = 0;
	int currentSegments = 0;
	FOR(i, 0, n)
	{
		if (i - w >= 0)
		{
			currentSegments -= segments[i - w];
		}
		if (flowers[i] + currentSegments < middle)
		{
			segments[i] = middle - flowers[i] - currentSegments;
			currentSegments += segments[i];
			moves += segments[i];
		}
		if (moves > m)
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	cin >> n >> m >> w;
	int low = 1;
	int high = 0;
	FOR(i, 0, n)
	{
		cin >> flowers[i];
		high = max(high, flowers[i]);
	}
	high += w;
	int answer = 0;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (check(middle))
		{
			answer = middle;
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	cout << answer << endl;

}