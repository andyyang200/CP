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
#include <stack>
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
int l[100000],r[100000],a[100000],d[100001],cnt[100001],n;
stack<int> s;
bool inStack[100001];
int main(void){
	freopen("art2.in","r",stdin);
	freopen("art2.out","w",stdout);
	scanf("%d", &n);
	rep(i,1,n+1)l[i]=inf;
	rep(i,0,n){
		int c;
		scanf("%d",&c);
		a[i]=c;
		cnt[c]++;
		l[c]=min(l[c],i);
		r[c]=max(r[c],i);
	}
	stack<int> s;
	rep(i,0,n){
		int c=a[i];
		if (cnt[c]==1){
			cnt[c]--;
			continue;
		}
		if (inStack[c]){
			if (s.top()==c){
				s.pop();
				cnt[c]-=2;
				inStack[c]=false;
			}
			else{
				printf("%d\n",-1);
				return 0;
			}
		}
		else{
			s.push(c);
			inStack[c]=true;
		}
	}
	rep(i,1,n+1){
		if (l[i]!=inf){
			d[l[i]]++;
			d[r[i]+1]--;
		}
	}
	int ans=0,cur=0;
	rep(i, 0, n){
		cur+=d[i];
		ans=max(ans,cur);
	}
	printf("%d\n", ans);
}