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
int x[1001];
int main()
{
	vector<int> a;
	vector<int> b;
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	int limit;
	if (n % 2 == 0)
	{
		limit = (n - 1) / 2;
	}
	else
	{
		limit = n / 2;
	}
	FOR(i, 0, limit + 1)
	{
		a.push_back(x[i]);
	}
	FOR(i, limit + 1, n)
	{
		b.push_back(x[i]);
	}
	int indA = 0;
	int indB = 0;
	FOR(i, 0, n)
	{
		if (i % 2 == 0)
		{
			x[i] = a[indA++];
		}
		else
		{
			x[i] = b[indB++];
		}
	}
	FOR(i, 0, n)
	{
		if (i % 2 == 0 && i > 0 && x[i] > x[i - 1])
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if (i % 2 == 1 && x[i] < x[i - 1])
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	FOR(i, 0, n)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}