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
int count(string s, char c)
{
	int ret = 0;
	FOR(i, 0, s.length())
	{
		if (s[i] == c)
		{
			ret++;
		}
	}
	return ret;
}
string a[101];
string b[101];
int main(void)
{
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i] >> b[i];
	}
	FOR(i, 0, 26)
	{
		int ans = 0;
		FOR(j, 0, n)
		{
			ans += max(count(a[j], 'a' + i), count(b[j], 'a' + i));
		}
		cout << ans << endl;
	}
}