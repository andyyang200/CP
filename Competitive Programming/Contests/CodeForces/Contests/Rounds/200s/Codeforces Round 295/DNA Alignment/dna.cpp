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
int c[26];
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int maxCount = 0;
	FOR(i, 0, n)
	{
		c[s[i] - 'A']++;
		maxCount = max(maxCount, c[s[i] - 'A']);
	}
	int k = 0;
	FOR(i, 0, 26)
	{
		if (c[i] == maxCount)
		{
			k++;
		}
	}
	ll ans = 1;
	FOR (i, 0, n)
	{
		ans *= k;
		ans %= 1000000007;
	}
	cout << ans << endl;
}