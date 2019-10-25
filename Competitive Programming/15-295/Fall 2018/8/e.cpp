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

set<int> SCCEdges[200005];
bool visited[200005];
vector<int> tsort;
int dp[200005];
void toposort(int u) {
	if (visited[u]) {
		return;
	}
	visited[u] = true;
	for (int v : SCCEdges[u]) {
		toposort(v);
	}
	tsort.push_back(u);
}

struct mine {
    int p, r, L, R, id;
    bool operator<(const mine o) const{
        return p < o.p;
    }
};

mine mines[200005];
int n;

int ans[200005];

int main(){
    scanf("%d", &n);
    FOR(i, 0, n){
        int p, r;
        scanf("%d%d", &p, &r);
        mines[i] = {p, r, p - r, p + r, i};
    }
    sort(mines, mines + n);
    stack<int> st;
    FOR(i, 0, n) {
        while (!st.empty() && mines[st.top()].R < mines[i].p) st.pop();
        if (!st.empty()) edges[st.top()].push_back(i);
        while (!st.empty() && mines[st.top()].R < mines[i].R) st.pop();
        st.push(i);
    }
    while(st.size())st.pop();
    RFOR(i, n - 1, -1){
        while (!st.empty() && mines[st.top()].L > mines[i].p) st.pop();
        if (!st.empty()) edges[st.top()].push_back(i);
        while (!st.empty() && mines[st.top()].L > mines[i].L) st.pop();
        st.push(i);
    }
    fill(dfs_num, dfs_num + n, -1);
    FOR(i, 0, n){
        if (dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }

    FOR(u, 0, n) {
		for (int v : edges[u]) {
			if (SCCNum[u] != SCCNum[v]) {
				SCCEdges[SCCNum[u]].insert(SCCNum[v]);
			}
		}
	}
	FOR(i, 0, SCCCount) {
		toposort(i);
	}
	FOR(i, 0, n){
        dp[SCCNum[i]]++;
	}
	FOR(i, 0, SCCCount) {
		for (int v : SCCEdges[u]) {
s		int u = tsort[i];
			dp[u] += dp[v];
		}
	}
    FOR(i, 0, n){
        ans[mines[i].id] = dp[SCCNum[i]];
    }
    FOR(i, 0, n){
        cout << ans[i] << " ";
    }
    cout << endl;
}


