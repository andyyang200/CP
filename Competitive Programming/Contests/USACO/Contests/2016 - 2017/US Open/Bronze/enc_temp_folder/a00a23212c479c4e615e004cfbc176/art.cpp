#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const int inf = 1e9;
const ll mod = 1000000007;
ll powmod(ll a, ll b)
{
	ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1)
	{
		if (b & 1)res = res*a%mod; a = a*a%mod;
	}return res;
}
int a[10][10], n;
int a2[10][10];
PII loc[10];
PII loc2[10];
int used[10];
int ans[10];
VI ord;
void dfs()
{
	if (ord.size() && ans[ord[0]])
	{
		return;
	}
	bool found = false;
	rep(i, 1, 10)
	{
		if (loc[i].fi < inf && !used[i])
		{
			ord.pb(i);
			used[i] = true;
			dfs();
			ord.pop_back();
			used[i] = false;
			found = true;
		}
	}
	if (!found)
	{
		rep(i, 0, n)
		{
			rep(j, 0, n)
			{
				a2[i][j] = 0;
			}
		}
		for (int c : ord)
		{
			rep(i, loc[c].fi, loc2[c].fi + 1)
			{
				rep(j, loc[c].se, loc2[c].se + 1)
				{
					a2[i][j] = c;
				}
			}
		}
		bool good = true;
		rep(i, 0, n)
		{
			rep(j, 0, n)
			{
				if (a[i][j] != a2[i][j])
				{
					good = false;
					break;
				}
			}
		}
		if (good)
		{
			ans[ord[0]] = 1;
		}
	}
}
int main(void)
{
	//freopen("art.in", "r", stdin);
	//freopen("art.out", "w", stdout);
	rep(i, 0, 10)
	{
		loc[i] = mp(inf, inf);
	}
	scanf("%d", &n);
	rep(i, 0, n)
	{
		rep(j, 0, n)
		{
			char c;
			cin >> c;
			int x = c - '0';
			a[i][j] = c;
			if (x != 0)
			{
				loc[x].fi = min(loc[x].fi, i);
				loc[x].se = min(loc[x].se, j);
				loc2[x].fi = max(loc2[x].fi, i);
				loc2[x].se = max(loc2[x].se, j);
			}
		}
	}
	dfs();
	int a = 0;
	rep(i, 1, 10)
	{
		a += ans[i];
	}
	printf("%d\n", a);
}