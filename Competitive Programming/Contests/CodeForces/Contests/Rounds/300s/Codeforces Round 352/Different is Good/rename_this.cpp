//Andrew Yang
#define _CRT_SECURE_NO_DEPRECATE
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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool seen[26];
int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n > 26)
	{
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		if (seen[s[i] - 'a'])
		{
			ans++;
		}
		seen[s[i] - 'a'] = true;
	}
	cout << ans << endl;
}