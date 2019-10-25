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
vector<int> edges[100005];
int a[100005];
vector<int> nodes[105];
int d[105][100005];
int temp[1005];
int main(){
    int n, m, s, k;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    FOR(i, 0, n){
        scanf("%d", &a[i]);
        a[i]--;
        nodes[a[i]].push_back(i);
    }
    FOR(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    FOR(good, 0, k){
        FOR(i, 0, n){
            d[good][i] = INF;
        }
        queue<int> q;
        for(int x : nodes[good]){
            q.push(x);
            d[good][x] = 0;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : edges[u]){
                if (d[good][v] == INF){
                    d[good][v] = d[good][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    FOR(i, 0, n){
        FOR(good, 0, k){
            temp[good] = d[good][i];
        }
        sort(temp, temp + k);
        int ans = 0;
        FOR(i, 0, s){
            ans += temp[i];
        }
        printf("%d ", ans);
    }
    printf("\n");

}


