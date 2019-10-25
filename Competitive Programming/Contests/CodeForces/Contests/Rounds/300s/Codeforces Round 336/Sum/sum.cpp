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
int prefix0[200001];
int prefix1[200001];
int count0(int a, int b)
{
	return prefix0[b] - (a == 0 ? 0 : prefix0[a - 1]);
}
int count1(int a, int b)
{
	return prefix1[b] - (a == 0 ? 0 : prefix1[a - 1]);
}
int main()
{
	string a, b;
	cin >> a >> b;
	FOR(i, 0, b.length())
	{
		if (i == 0)
		{
			prefix0[i] = (b[i] == '0');
			prefix1[i] = (b[i] == '1');
		}
		else
		{
			prefix0[i] = prefix0[i - 1] + (b[i] == '0');
			prefix1[i] = prefix1[i - 1] + (b[i] == '1');
		}
	}
	ll ans = 0;
	FOR(i, 0, a.length())
	{
		if (a[i] == '0')
		{
			ans += (ll)count1(i, b.length() - 1 - (a.length() - 1 - i));
		}
		else
		{
			ans += (ll)count0(i, b.length() - 1 - (a.length() - 1 - i));
		}
	}
	cout << ans << endl;
}