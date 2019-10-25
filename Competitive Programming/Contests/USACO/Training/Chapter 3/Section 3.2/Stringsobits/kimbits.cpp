/*
ID: andyyang200
PROG: kimbits
LANG: C++11
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

int ways[32][32]; // length, max 1's;

int main()
{
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);

	ll n, l, i;
	cin >> n >> l >> i;
	for (int x = 0; x <= 32; x++)
	{
		ways[x][0] = 1;
		ways[0][x] = 1;
	}
	for (int r = 1; r <= 31; r++)
	{
		for (int c = 1; c <= 31; c++)
		{
			ways[r][c] = ways[r - 1][c] + ways[r - 1][c - 1];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		int count = ways[n - k][l];
		if (i > count)
		{
			cout << "1";
			i -= count;
			l--;
		}
		else
		{
			cout << "0";
		}
	}
	cout << endl;
}
