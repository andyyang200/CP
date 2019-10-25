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
int n, m;
string ballots[5005];
int RA[5005][26];
int cnt[5005];
vector<int> edges[50];
bool win(int a, int b){
    int avote = 0;
    int bvote = 0;
    FOR(i, 0, m){
        if (RA[i][a] < RA[i][b]){
            avote += cnt[i];
        }
        else{
            bvote += cnt[i];
        }
    }
    return avote > bvote;
}
bool visited[50];
void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for(int v : edges[u])dfs(v);
}
bool canwin(int c){
    FOR(i, 0, n) visited[i] = false;
    dfs(c);
    FOR(i, 0, n) if (!visited[i]) return false;
    return true;
}
int main(){;
    scanf("%d%d", &n, &m);
    FOR(i, 0, m){
        scanf("%d", &cnt[i]);
        cin >> ballots[i];
        FOR(j, 0, n){
            RA[i][ballots[i][j] - 'A'] = j;
        }
    }
    FOR(i, 0, n){
        FOR(j, 0, n){
            if (i == j) continue;
            if (win(i, j)){
                edges[i].push_back(j);
            }
        }
    }
    FOR(i, 0, n){
        cout << (char)('A' + i) << ": " << (canwin(i) ? "can win" : "can't win");
        cout << endl;
    }
}


