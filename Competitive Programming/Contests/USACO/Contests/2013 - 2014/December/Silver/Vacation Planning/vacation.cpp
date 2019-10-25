#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
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
#include <limits>
#include <climits>
#define infinity LLONG_MAX
using namespace std;

long long d[205][205];

int main()
{
	ifstream fin("vacation.in");
	ofstream fout("vacation.out");

	int n, m, k, q;
	fin >> n >> m >> k >> q;

	for (int x = 0; x < m; x++)
	{
		int a, b;
		fin >> a >> b;
		fin >> d[a][b];
	}
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= n; c++)
		{
			if (r != c && d[r][c] == 0)
			{
				d[r][c] = infinity;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int start = 1; start <= n; start++)
		{
			for (int end = 1; end <= n; end++)
			{
				if (d[start][i] != infinity &&  d[i][end] != infinity)
				{
					long long dis = d[start][i] + d[i][end];
					if (dis < d[start][end])
					{
						d[start][end] = dis;
					}
				}
			}
		}
	}
	int count = 0;
	long long minCost = 0;
	for (int x = 0; x < q; x++)
	{
		int a, b;
		fin >> a >> b;
		long long min = infinity;
		for (int i = 1; i <= k; i++)
		{
			if (d[a][i] != infinity &&  d[i][b] != infinity && d[a][i] + d[i][b] < min)
			{
				min = d[a][i] + d[i][b];
			}
		}
		if (min < infinity)
		{
			count++;
			minCost += min;
		}
	}
	fout << count << endl << minCost << endl;
}