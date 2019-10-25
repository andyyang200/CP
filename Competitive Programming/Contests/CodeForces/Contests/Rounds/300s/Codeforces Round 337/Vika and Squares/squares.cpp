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
int a[200001];
int main()
{
	int n;
	scanf("%d", &n);
	int mn = INF;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}
	vector<int> mins;
	FOR(i, 0, n)
	{
		if (a[i] == mn)
		{
			mins.push_back(i);
		}
	}
	int maxDist = 0;
	FOR(i, 1, mins.size())
	{
		maxDist = max(maxDist, mins[i] - mins[i - 1]);
	}
	maxDist = max(maxDist, mins[0] + n - mins[mins.size() - 1]);
	cout << (ll)mn * n + maxDist - 1 << endl;

}