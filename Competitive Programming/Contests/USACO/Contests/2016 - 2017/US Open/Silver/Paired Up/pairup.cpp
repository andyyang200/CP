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
PII a[100000];
int main(void){
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	int n;
	scanf("%d", &n);
	rep(i,0,n)
		scanf("%d%d",&a[i].second,&a[i].first);
	sort(a,a+n);
	int i=0,j=n-1,ans=0;
	while (i<j)
	{
		ans=max(ans,a[i].first+a[j].first);
		int x=min(a[i].second,a[j].second);
		a[i].second-=x;
		if (a[i].second==0) i++;
		a[j].second-=x;
		if (a[j].second==0) j--;
	}
	if (i==j&&a[i].se>0)
		ans = max(ans, a[i].se<<1);
	printf("%d\n", ans);
}