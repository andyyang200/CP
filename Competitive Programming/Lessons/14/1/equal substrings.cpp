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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
/*
You have two strings, both of length N. What is the length of the longest string that is a substring of both strings?
N <= 100000
*/








int n, m;
char str[120000];
const long long mul1 = 10007;
const long long mul2 = 131;
const long long mod = 1000000007;
struct hash
{
	int len;
	pair<long long, long long>exp[120000], val[120000];
	inline void build(int ll)
	{
		len = ll;
		exp[0] = make_pair(1, 1);
		val[0] = make_pair(0, 0);
		for (int i = 1; i <= ll; i++)
		{
			int cur = str[i] - 'a' + 1;
			exp[i] = make_pair(exp[i - 1].first*mul1%mod, exp[i - 1].second*mul2%mod);
			val[i] = make_pair((val[i - 1].first + cur*exp[i].first%mod) % mod, (val[i - 1].second + cur*exp[i].second%mod) % mod);
		}
	}
	inline pair<long long, long long> query(int le, int ri)
	{
		return make_pair(((val[ri].first - val[le - 1].first + mod) % mod)*exp[len - le].first%mod, ((val[ri].second - val[le - 1].second + mod) % mod)*exp[len - le].second%mod);
	}
}sgt1, sgt2;
int cnt;
set<pair<long long, long long> >mp;
inline bool check(int ll)
{
	mp.clear();
	for (int i = 1; i <= n - ll + 1; i++)
	{
		mp.insert(sgt1.query(i, i + ll - 1));
	}
	for (int i = 1; i <= m - ll + 1; i++)
	{
		if (mp.count(sgt2.query(i, i + ll - 1)) != 0)return true;
	}return false;
}
int main()
{
	scanf("%d", &n);
	m = n;
	scanf("%s", str + 1);
	if (n<m)
	{
		for (int i = n + 1; i <= m; i++)
		{
			str[i] = 1;
		}
		n = m;
	}
	sgt1.build(n);
	scanf("%s", str + 1);
	if (m<n)
	{
		for (int i = m + 1; i <= n; i++)
		{
			str[i] = 1;
		}
		m = n;
	}
	sgt2.build(m);
	int le = 0, ri = min(n, m), mi;
	while (le<ri)
	{
		mi = (le + ri + 1) / 2;
		if (check(mi))
		{
			le = mi;
		}
		else
		{
			ri = mi - 1;
		}
	}printf("%d\n", le);
	return 0;
}