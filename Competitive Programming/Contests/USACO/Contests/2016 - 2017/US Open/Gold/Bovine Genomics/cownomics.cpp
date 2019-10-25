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
#include <unordered_set>
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
const ll p = 5;
ll powmod(ll a, ll b)
{
	ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1)
	{
		if (b & 1)res = res*a%mod; a = a*a%mod;
	}return res;
}
int n, m;
string g[1000];
vector<ll> h[1000];
ll powers[2000];
ll get(int i,int a,int b){
	ll ret=h[i][b];
	if (a>0)
		ret-=(h[i][a-1]*powers[b-a+1])%mod;
	while (ret<0)
		ret+=mod;
	return ret;
}
bool check(int a,int b){
	set<ll> s;
	rep(i,0,n)
		s.insert(get(i,a,b));
	rep(i,n,2*n)
		if (s.find(get(i,a,b))!=s.end())
			return false;
	return true;
}
int main(void){
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	scanf("%d%d",&n,&m);
	powers[0]=1;
	rep(i,1,2000) 
		powers[i]=(powers[i - 1]*p)%mod;
	rep(i,0,2*n){
		cin>>g[i];
		h[i].pb(g[i][0]-'A');
		rep(j,1,m)
			h[i].pb((h[i].back()*p+g[i][j]-'A')%mod);
	}
	int ans=m;
	rep(i,0,m){
		int l=i,r=m-1;
		while (l<=r){
			int mid=(l+r)>>1;
			if (check(i,mid)){
				ans = min(ans,mid-i+1);
				r=mid-1;
			}
			else
				l=mid+1;
		}
	}
	printf("%d\n",ans);
}