//Andrew Yang
// accepted
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
pair<ll, ll> f(ll n, ll k)
{
	n--;
	ll mid = n / 2;
	ll left = mid;
	ll right = n - mid;
	if (k == 1)
	{
		return { max(left, right), min(left, right) };	
	}
	k--;
	if (k % 2 == 0)
	{
		return f(left, k / 2);
	}
	else
	{
		return f(right, k / 2 + 1);
	}
}
int main(void)
{
	freopen("stalls.in", "r", stdin);
	freopen("stalls.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		ll n, k;
		cin >> n >> k;
		pair<ll, ll> ans = f(n, k);
		cout << "Case #" << test + 1 << ": " << ans.first << " " << ans.second << endl;
	}
	
}