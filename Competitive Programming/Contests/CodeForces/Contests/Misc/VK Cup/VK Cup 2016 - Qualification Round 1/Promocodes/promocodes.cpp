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
string codes[1001];
int errors(string& a, string& b)
{
	int ret = 0;
	FOR(i, 0, 6)
	{
		if (a[i] != b[i])
		{
			ret++;
		}
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		cout << 6 << endl;
		return 0;
	}
	int ans = 6;
	FOR(i, 0, n)
	{
		cin >> codes[i];
	}
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			int x = errors(codes[i], codes[j]);
			ans = min(ans, (int)ceil((double)x / 2));
		}
	}
	cout << ans - 1 << endl;
}