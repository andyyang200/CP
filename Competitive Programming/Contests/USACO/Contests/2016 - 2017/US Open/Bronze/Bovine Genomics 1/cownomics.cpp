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
char c[200][100];
int n,m,ans=0;
int main(void){
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i,0,n<<1)rep(j,0,m)cin>>c[i][j];
	rep(j,0,m){
		set<char> a;
		rep(i,0,n)a.insert(c[i][j]);
		bool bad = false;
		rep(i, n, 2 * n)
			if (a.find(c[i][j]) != a.end())
				bad = true;
		if (!bad)ans ++;
	}
	printf("%d\n",ans);
}