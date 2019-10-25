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
double pLeft[2001];
double pRight[2001];
int x[2001];
int main()
{
	int n, h;
	scanf("%d%d", &n, &h);
	double p;
	cin >> p;
	FOR(i, 0, n)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	pRight[0] = 0.5 * (1 - p);
	FOR(i, 1, n)
	{
		if (x[i] - x[i - 1] < h)
		{

		}
	}
}