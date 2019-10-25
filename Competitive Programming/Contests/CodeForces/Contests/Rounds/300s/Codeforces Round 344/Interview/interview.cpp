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
int a[1001];
int b[1001];
int main()
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n)
	{
		scanf("%d", &b[i]);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		int or1 = a[i];
		int or2 = b[i];
		ans = max(ans, or1 + or2);
		FOR(j, i + 1, n)
		{
			or1 = or1 | a[j];
			or2 = or2 | b[j];
			ans = max(ans, or1 + or2);
		}
	}
	cout << ans << endl;
}