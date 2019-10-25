#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int p[105];
int res[105][105];
int dist[105];
ll mf, f;
int s, t;
int n, m;
void augment(int v, int minEdge){
	if (v == s){
		f = minEdge;
		return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
ll maxflow(){
	mf = 0;
	while (true){
		f = 0;
		FOR(i, 0, n){
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			if (u == t){
				break;
			}
			for (int v = 0; v < n; v++){
				if (res[u][v] > 0 && dist[v] == 1000000000){
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, 1000000000);
		if (f == 0){
			break;
		}
		mf += f;
	}
	return mf;
}

int main(){
    ri2(n, m);
    ri2(s, t);
    s--;
    t--;
    FOR(i, 0, m){
        int u, v, c;
        ri3(u, v, c);
        u--;
        v--;
        if (u != v){
            res[u][v] += c;
        }
    }
    cout << maxflow() << endl;
}

