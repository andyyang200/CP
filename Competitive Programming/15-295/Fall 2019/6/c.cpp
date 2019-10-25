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
typedef pair<ll, ll> pii;


//---------------------------------------------------------------------------------------------------------------
vector<pii> edges[300000]; // distance to source, end node number; initialize
ll d[300000];
int n, m, k; // initialize
map<pii, int> index;
vector<int> ans;
int p[300005];
void dijkstra(int source)
{
	FOR(i, 0, n)
	{
		d[i] = 100000000000000000;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[source] = 0;
	nodes.push(pii(0, source));
	while(!nodes.empty()){
	{
	    if (nodes.empty()){
            break;
	    }
		ll dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[node])
		{
			continue;
		}
        if (node != 0)
            ans.push_back(p[node]);
		if (ans.size() == k){
            break;
		}

		for (pii edge : edges[node])
		{
			if (d[node] + edge.first < d[edge.second])
			{
			    p[edge.second] = index[{node, edge.second}];
				d[edge.second] = d[node] + edge.first;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
}
}
int main(){
    ri3(n, m, k);
    FOR(i, 0, m){
        int x, y, z;
        ri3(x, y, z);
        x--;
        y--;
        edges[x].push_back({z, y});
        edges[y].push_back({z, x});
        index[{x, y}] = i;
        index[{y, x}] = i;
    }
    dijkstra(0);
    printf("%d\n", ans.size());
    for(int x : ans){
        printf("%d ", x + 1);
    }
    printf("\n");
}
