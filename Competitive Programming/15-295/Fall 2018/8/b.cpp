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

vector<int> edges[200005];
int dfs_num[200005];     // initialize to -1
int dfs_low[200005];
int dfsNumberCounter = 0;
vector<int> S;
int inStack[200005];
int SCCCount = 0;

int SCCNum[200005]; // SCCNum[i] is the SCC number that node i is in
vector<int> SCC[200005]; // list of nodes of each SCC

void tarjanSCC(int u) { // call on every node with dfs_num = -1
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	inStack[u] = 1;
	for(int v : edges[u]){
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (inStack[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) { // new scc
		while (1) {
			int v = S.back();
			S.pop_back();
			inStack[v] = 0;

            //v is a new node in the scc
            // DO IMPORTANT STUFF HERE
            SCCNum[v] = SCCCount;
            SCC[SCCCount].push_back(v);


			if (u == v) break;
		}
		SCCCount++;
	}
}
int c[100005];
int incoming[100005];
int minValue[100005];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 0, n){
        scanf("%d", &c[i]);
    }
    FOR(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    FOR(i, 0, n){
        dfs_num[i] = -1;
    }
    FOR(i, 0, n){
        if (dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }
    FOR(i, 0, SCCCount){
        minValue[i] = INF;
    }
    FOR(i, 0, n){
        minValue[SCCNum[i]] = min( minValue[SCCNum[i]], c[i]);
    }
    FOR(u, 0, n){
        for(int v: edges[u]){
            if (SCCNum[u] != SCCNum[v])
                incoming[SCCNum[v]]++;
        }
    }
    ll ans = 0;
    FOR(i, 0, SCCCount){
        if (incoming[i] == 0) ans += minValue[i];
    }
    cout << ans << endl;
}

