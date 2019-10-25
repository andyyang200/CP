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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int limit[200001];
int used[200001];
int main(void)
{
	ll m;
	cin >> m;
	int n = 1;
	ll sum = 0;
	for (ll i = 1; ; i++)
	{
		n = i;
		ll a = i * i * i;
		if (a > m)
		{
			break;
		}
		ll b = (i + 1) * (i + 1) * (i + 1) - sum;
		if (b % a == 0)
		{
			limit[i] = b / a - 1;
		}
		else
		{
			limit[i] = b / a;
		}
		sum += a * limit[i];
	}
	sum = 0;
	int cnt = 0;
	FOR(i, 1, n)
	{
		ll v = (ll)i * i * i;
		if (sum + v > m)
		{
			break;
		}
		FOR(j, 0, limit[i])
		{
			if (sum + v <= m)
			{
				sum += v;
				cnt++;
				used[i]++;
			}
			else
			{
				break;
			}
		}
	}
	RFOR(i, n - 2, 0)
	{
		ll a = i * i * i;
		ll b = (i + 1) * (i + 1) * (i + 1);
		while (used[i + 1] < limit[i + 1] && used[i] > 0 && sum - a + b <= m)
		{
			sum = sum - a + b;
			used[i]--;
			used[i + 1]++;
		}
	}
	cout << cnt << " " << sum << endl;
}