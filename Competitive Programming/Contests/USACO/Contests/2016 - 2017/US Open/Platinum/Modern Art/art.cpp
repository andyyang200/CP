#include <iostream>
#include <sstream>
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
#define FOR(i,a,n) for (int i=a;i<n;i++)
#define FORREV(i,a,n) for (int i=n-1;i>=a;i--)
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
const int INF = 1e9;

int tr[1000002];
int br[1000002];
int lc[1000002];
int rc[1000002];
int ori[1001][1001];
int n;
struct S
{
	int t, b, l, r, c;
};
bool visit[1000002];
int avail;
map<int, S> lookup;

void handle(S s)
{
	if (visit[s.c]) return;
	visit[s.c] = true;
	FOR(j, s.t, s.b + 1)
		FOR(k, s.l, s.r + 1)
	{
		int c2 = ori[j][k];
		if (c2 != s.c && c2 != 0)
		{
			if (visit[c2] == false)
			{
				handle(lookup[c2]);
				avail--;
			}
		}
	}
}
int main(void)
{
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	scanf("%d", &n);
	avail = n * n;
	FOR(i, 0, n*n + 1)
	{
		tr[i] = INF;
	}
	FOR(i, 0, n)
		FOR(j, 0, n)
	{
		int c;
		scanf("%d", &c);
		ori[i][j] = c;
		if (c == 0)
			continue;
		if (tr[c] == INF)
		{
			tr[c] = br[c] = i;
			lc[c] = rc[c] = j;
		}
		else
		{
			tr[c] = min(i, tr[c]);
			br[c] = max(i, br[c]);
			lc[c] = min(j, lc[c]);
			rc[c] = max(j, rc[c]);
		}
	}
	int count = 0;
	vector<S> col;
	FOR(i, 1, n*n + 1)
	{
		if (tr[i] == INF)
		{
			count++;
		}
		else
		{
			S s;
			s.l = lc[i];
			s.r = rc[i];
			s.t = tr[i];
			s.b = br[i];
			s.c = i;
			col.pb(s);
			lookup[i] = s;
		}
	}
	std::sort(col.begin(), col.end(), [](S a, S b) {
		return (b.r - b.l + 1) * (b.b - b.t + 1) < (a.r - a.l + 1) * (a.b - a.t + 1);
	});
	FOR(i, 0, col.size())
	{
		handle(col[i]);
	}
	cout << avail << endl;
}
/*
4
9 1 1 1
1 1 2 3
1 1 2 4
1 1 5 6
*/