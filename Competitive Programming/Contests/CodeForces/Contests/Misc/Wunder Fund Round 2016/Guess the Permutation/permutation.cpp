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
int a[100][100];
int ans[100];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
	FOR(i, 0, n)
	{
		int m = 0;
		FOR(j, 0, n)
		{
			m = max(m, a[i][j]);
		}
		ans[i] = m;
	}
	FOR(i, 0, n)
	{
		if (ans[i] == n - 1)
		{
			ans[i] = n;
			break;
		}
	}
	FOR(i, 0, n)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}