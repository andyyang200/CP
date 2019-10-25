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
int s[300001];
int main()
{
	string str;
	cin >> str;
	FOR(i, 0, str.length())
	{
		s[i] = str[i] - '0';
	}
	ll ans = 0;
	FOR(i, 0, str.length() - 1)
	{
		if ((10 * s[i] + s[i + 1]) % 4 == 0)
		{
			ans += i + 1;
		}
	}
	FOR(i, 0, str.length())
	{
		if (s[i] % 4 == 0)
		{
			ans++;
		}
	}
	cout << ans << endl;
}