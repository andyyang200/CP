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
// begin dinics
int adj[100][100];
int p[100];
int res[100][100];
ll mf, f;
int s, t;
int n, m, x;
void augment(int v, int minEdge)
{
	if (v == s)
	{
		f = minEdge;
		return;
	}
	else if (p[v] != -1)
	{
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int maxflow()
{
	s = 0;
	t = n - 1;
	mf = 0;
	while (true)
	{
		f = 0;
		int dist[100];
		FOR(i, 0, n)
		{
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u == t)
			{
				break;
			}
			for (int v = 0; v < n; v++)
			{
				if (res[u][v] > 0 && dist[v] == 1000000000)
				{
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, 1000000000);
		if (f == 0)
		{
			break;
		}
		mf += f;
	}
	return mf;
}
bool check(double v){
	FOR(i, 0, n){
		FOR(j, 0, n){
			ll bears = (ll)adj[i][j] / v;
			if (bears > x){
				bears = x;
			}
			res[i][j] = bears;
		}
	}
	return maxflow() >= x;
}
int main(){
	scanf("%d%d%d", &n, &m, &x);
	double low = 0;
	double high = 0;
	FOR(i, 0, m){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		adj[a][b] = c;
		high = max(high, (double)c);
	}
	double ans = 0;
	FOR(i, 0, 100){
		double mid = (low + high) / 2;
		if (check(mid)){
			low = mid;
			ans = max(ans, mid);
		}
		else{
			high = mid;
		}
	}
	printf("%.11f\n", ans * x);
}

