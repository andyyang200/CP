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
int x,y;
int main(void){
	freopen("lostcow.in","r",stdin);
	freopen("lostcow.out","w",stdout);
	scanf("%d%d",&x,&y);
	y-=x,x=0;
	int p=0,p2=1,a=0;
	while(true){
		if (y>=min(p, p2)&&y<=max(p,p2)){
			a+=abs(p-y);
			break;
		}else{
			a+=abs(p-p2);
			p=p2;
			p2*=-2;
		}
	}
	printf("%d\n",a);
}