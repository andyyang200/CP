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

int x[100005];
int y[100005];

int calcDistance(int a, int b)
{
	return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main()
{
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (i > 0)
		{
			total += calcDistance(i, i - 1);
		}
	}
	int max = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int d = calcDistance(i, i - 1) + calcDistance(i, i + 1) - calcDistance(i - 1, i + 1);
		if (d > max)
		{
			max = d;
		}
	}
	total -= max;
	cout << total << endl;
}