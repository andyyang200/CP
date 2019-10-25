#include<bits/stdc++.h>
using namespace std;
#ifndef d
#define d(...)
#endif
#define st first
#define nd second
#define pb push_back
#define siz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
typedef long long LL;
typedef long double LD;
constexpr int INF=1e9+7;
constexpr LL INFL=1e16;

const int maxn=10005,maxk=105,maxx=1e6+5;

int n,k,rozm=1;
LL dp[maxn][maxk];
int tab[maxn];

struct line
{
	LL a,b;
	line(LL va=0,LL vb=INFL)
	{
		a=va,b=vb;
	}
	LL get(LL x)
	{
		return a*x+b;
	}
} lichao[4*maxx];

void clear(){
	for(int i=1;i<2*rozm;i++)
		lichao[i]=line();
}

void insert(line nw,int a=1,int l=1,int r=rozm)
{
	int m=(l+r)/2;
	bool lft= nw.get(l) < lichao[a].get(l);
	bool mid= nw.get(m) < lichao[a].get(m);
	if(mid)
		swap(nw,lichao[a]);
	if(l==r)
		return;
	if(lft!=mid)
		insert(nw,2*a,l,m);
	else
		insert(nw,2*a+1,m+1,r);
}

LL query(int x,int a=1,int l=1,int r=rozm)
{
	int m=(l+r)/2;
	if(l==r)
		return lichao[a].get(x);
	if(x<=m)
		return min(lichao[a].get(x),query(x,2*a,l,m));
	return min(lichao[a].get(x),query(x,2*a+1,m+1,r));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
		mx=max(mx,tab[i]);
	}
	while(rozm<mx)
		rozm<<=1;
	for(int i=1;i<=n;i++)
		dp[i][0]=INFL;
	for(int i=1;i<=k;i++){
		clear();
		for(int j=i-1;j<n;j++){
			insert(line(-2*tab[j+1],(LL)tab[j+1]*tab[j+1]+dp[j][i-1]));
			dp[j+1][i]=(LL)tab[j+1]*tab[j+1]+query(tab[j+1]);
		}
	}
	cout<<dp[n][k]<<"\n";

	return 0;
}
