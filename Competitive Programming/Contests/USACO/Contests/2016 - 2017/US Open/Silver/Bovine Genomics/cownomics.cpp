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
const int p = 5;
ll powmod(ll a, ll b)
{
	ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1)
	{
		if (b & 1)res = res*a%mod; a = a*a%mod;
	}return res;
}
int n, m, grid[1000][50],ans=0;
int getHash(int a,int b,int c){
	return 25 * a + 5 * b + c;
}
int main(void)
{
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,0,n<<1)
	{
		rep(j,0,m)
		{
			char c;
			cin>>c;
			if (c=='A')	grid[i][j]=1;
			else if (c=='C') grid[i][j]=2;
			else if (c=='G') grid[i][j]=3;
			else grid[i][j] = 4;
		}
	}
	rep(i,0,m){
		rep(j,i+1,m){
			rep(k,j+1,m){
				unordered_set<int> a;
				rep(x,n,2*n){
					int h = getHash(grid[x][i],grid[x][j],grid[x][k]);
					a.insert(h);
				}
				bool bad=false;
				rep(x,0,n){
					int h=getHash(grid[x][i],grid[x][j],grid[x][k]);
					if (a.find(h)!=a.end()){
						bad=true;
						break;
					}
				}
				if (!bad) ans++;
			}
		}
	}
	printf("%d\n", ans);
}