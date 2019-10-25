#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

pii sharks[100001];
int nump[100001];
int main(){
	int n;
	scanf("%d", &n);
	int p;
	scanf("%d", &p);
	FOR(i, 0, n){
		scanf("%d%d", &sharks[i].first, &sharks[i].second);
	}
	FOR(i, 0, n){
		int minp = (sharks[i].first + p - 1) / p;
		int maxp = sharks[i].second / p;
		if (minp && maxp && minp <= maxp){
			nump[i] = maxp - minp + 1;
		}
		else{
			nump[i] = 0;
		}
	}
	double ans = 0;
	FOR(i, 0, n){
		double x = 0;
		x += (ll)nump[i] * (sharks[(i + 1) % n].second - sharks[(i + 1) % n].first + 1);
		x += (ll)nump[(i + 1) % n] * (sharks[i].second - sharks[i].first + 1);
		x -= (ll)nump[i] * nump[(i + 1) % n];
		x /= (sharks[i].second - sharks[i].first + 1);
		x /= (sharks[(i + 1) % n].second - sharks[(i + 1) % n].first + 1);
		x *= 2000;
		ans += x;
	}
	printf("%.9f\n", ans);
}

