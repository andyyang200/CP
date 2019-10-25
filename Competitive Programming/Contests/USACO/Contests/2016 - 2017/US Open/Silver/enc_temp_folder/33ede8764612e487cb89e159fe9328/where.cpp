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
const ll mod = 1000000007;
ll powmod(ll a, ll b)
{
	ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1)
	{
		if (b & 1)res = res*a%mod; a = a*a%mod;
	}return res;
}
char grid[20][20];
bool visited[20][20];
int r1;
int r2;
int c1;
int c2;
void dfs(int i, int j, char c)
{
	if (i < r1 || i > r2 || j < c1 || j > c2 || grid[i][j] != c || visited[i][j])
	{
		return;
	}
	visited[i][j] = true;
	dfs(i + 1, j, c);
	dfs(i - 1, j, c);
	dfs(i, j + 1, c);
	dfs(i, j - 1, c);
}
struct S
{
	int a, b, c, d;
};
int main(void)
{
	//freopen("where.in", "r", stdin);
	//freopen("where.out", "w", stdout);
	int n;
	scanf("%d", &n);
	rep(i, 0, n)
	{
		rep(j, 0, n)
		{
			cin >> grid[i][j];
		}
	}
	vector<S> v;
	for (r1 = 0; r1 < n; r1++)
	{
		for (r2 = r1; r2 < n; r2++)
		{
			for (c1 = 0; c1 < n; c1++)
			{
				for (c2 = c1; c2 < n; c2++)
				{
					bool good = true;
					rep(i, r1, r2 + 1)
					{
						rep(j, c1, c2 + 1)
						{
							visited[i][j] = false;
						}
					}
					char color1 = -1;
					char color2 = -1;
					int count1 = 0;
					int count2 = 0;
					rep(i, r1, r2 + 1)
					{
						if (!good)
						{
							break;
						}
						rep(j, c1, c2 + 1)
						{
							if (!good)
							{
								break;
							}
							if (!visited[i][j])
							{
								if (color1 == -1 || grid[i][j] == color1)
								{
									color1 = grid[i][j];
									count1++;
								}
								else if (color2 == -1 || grid[i][j] == color2)
								{
									color2 = grid[i][j];
								}
								else
								{
									good = false;
									break;
								}
								dfs(i, j, grid[i][j]);
								if (count1 > 1 && count2 > 1)
								{
									good = false;
									break;
								}
							}
							
						}
					}
					if (good && min(count1, count2) == 1 && max(count1, count2) > 1)
					{
						S s;
						s.a = r1;
						s.b = r2;
						s.c = c1;
						s.d = c2;
						v.push_back(s);
					}
				}
			}
		}
	}
	per(i, 0, v.size())
	{
		rep(j, 0, i)
		{
			if (v[j].a <= v[i].a && v[j].b >= v[i].b && v[j].c <= v[i].c && v[j].d >= v[i].d)
			{
				v.erase(v.begin() + i);
				break;
			}
		}
	}
	cout << v.size() << endl;
}