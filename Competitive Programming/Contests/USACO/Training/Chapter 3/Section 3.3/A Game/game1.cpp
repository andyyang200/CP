/*
ID: andyyang200
PROG: game1
LANG: C++
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

vector<int> numbers;
int best[2][100][100];
int main()
{
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int total = 0;
	FOR(i, 0, n)
	{
		int number;
		scanf("%d", &number);
		numbers.push_back(number);
		best[0][i][i] = number;
		best[1][i][i] = 0;
		total += number;
	}
	FOR(difference, 0, n)
	{
		FOR(i, 0, n)
		{
			int j = i + difference;
			if (j >= n)
			{
				break;
			}
			best[0][i][j] = max(best[1][i + 1][j] + numbers[i], best[1][i][j - 1] + numbers[j]);
			best[1][i][j] = min(best[0][i + 1][j], best[0][i][j - 1]);
		}
	}
	int a = best[0][0][n - 1];
	cout << a << " " << total - a << endl;
}