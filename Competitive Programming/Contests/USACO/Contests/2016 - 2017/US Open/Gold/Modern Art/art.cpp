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
const int inf = 1e9;
ll powmod(ll a, ll b)
{
	ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1)
	{
		if (b & 1)res = res*a%mod; a = a*a%mod;
	}return res;
}
int grid[40][40],n,minr[2000],maxr[2000],minc[2000],maxc[2000],dp[2000];
set<int> edges[2000];
bool visited[2000];
VI ord;
void dfs(int i){
	if (visited[i]){
		return;
	}
	visited[i]=true;
	for (int j:edges[i]){
		dfs(j);
	}
	ord.pb(i);
}
int main(void){
	freopen("art.in","r",stdin);
	freopen("art.out","w",stdout);
	scanf("%d", &n);
	rep(i,0,n*n+1){
		minr[i]=inf;
		minc[i]=inf;
	}
	rep(i,0,n){
		rep(j,0,n){
			int c;
			scanf("%d",&c);
			grid[i][j]=c;
			minr[c]=min(minr[c],i);
			minc[c]=min(minc[c],j);
			maxr[c]=max(maxr[c],i);
			maxc[c]=max(maxc[c],j);
		}
	}
	rep(c,1,n*n+1){
		if (minr[c]==inf) continue;
		rep(i,minr[c],maxr[c]+1){
			rep(j,minc[c],maxc[c]+1){
				if (grid[i][j]!=c){
					edges[c].insert(grid[i][j]);
				}
			}
		}
	}
	rep(c,1,n*n+1){
		if (minr[c]!=inf){
			dfs(c);
		}
	}
	reverse(ord.begin(),ord.end());
	int ans=0;
	per(i,0,ord.size()){
		int c=ord[i];
		dp[c]=1;
		for (int j:edges[c]){
			dp[c]=max(dp[c],dp[j]+1);
		}
		ans = max(ans, dp[c]);
	}
	printf("%d\n", ans);
}