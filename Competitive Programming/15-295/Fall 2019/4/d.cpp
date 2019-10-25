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
int d[251][251];
char grid[251][251];
int ans[100005];
int dr[4] = {-1 , 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
int n, e;
struct query{
    int i, r1, c1, r2, c2;
};
bool valid(int r, int c, int r1, int c1, int r2, int c2){
    return r >= r1 && r <= r2 && c >= c1 && c <= c2 && grid[r][c] == '.';
}
void bfs(int startr, int startc, int r1, int c1, int r2, int c2){
    FOR(i, r1, r2 + 1){
        FOR(j, c1, c2 + 1){
            d[i][j] = INF;
        }
    }
    queue<int> q;
    if (valid(startr, startc, r1, c1, r2, c2)){
        q.push(startr);
        q.push(startc);
        d[startr][startc] = 0;
    }
    while(!q.empty()){
        int r = q.front();
        q.pop();
        int c = q.front();
        q.pop();
        FOR(i, 0, 4){
            int rnext = r + dr[i];
            int cnext = c + dc[i];
            if (valid(rnext, cnext, r1, c1, r2, c2) && d[rnext][cnext] == INF){
                d[rnext][cnext] = d[r][c] + 1;
                q.push(rnext);
                q.push(cnext);
            }
        }
    }
}
void work(int r1, int r2, int c1, int c2, vector<query>& queries){
    if (r2 < r1 || c2 < c1) {
        return;
    }
    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;
    FOR(r, r1, r2 + 1){
        bfs(r, cm, r1, c1, r2, c2);
        for(query q : queries){
            ans[q.i] = min(ans[q.i], d[q.r1][q.c1] + d[q.r2][q.c2]);
        }
    }
    FOR(c, c1, c2 + 1){
        bfs(rm, c, r1, c1, r2, c2);
        for(query q : queries){
            ans[q.i] = min(ans[q.i], d[q.r1][q.c1] + d[q.r2][q.c2]);
        }
    }
    vector<query> a;
    vector<query> b;
    vector<query> c;
    vector<query> d;
    for(query q : queries){
        if (q.r1 < rm && q.r2 < rm && q.c1 < cm && q.c2 < cm){
            a.push_back(q);
        }
        else if (q.r1 < rm && q.r2 < rm && q.c1 > cm && q.c2 > cm){
            b.push_back(q);
        }
        else if (q.r1 > rm && q.r2 > rm && q.c1 < cm && q.c2 < cm){
            c.push_back(q);
        }
        else if (q.r1 > rm && q.r2 > rm && q.c1 > cm && q.c2 > cm){
            d.push_back(q);
        }
    }
    work(r1, rm - 1, c1, cm - 1, a);
    work(r1, rm - 1, cm + 1, c2, b);
    work(rm + 1, r2, c1, cm - 1, c);
    work(rm + 1, r2, cm + 1, c2, d);
}
int main(){
    ri2(n, e);
    FOR(i, 0, n){
        FOR(j, 0, n){
            cin >> grid[i][j];
        }
    }
    vector<query> queries;
    FOR(i, 0, e){
        int r1, c1, r2, c2;
        query q;
        q.i = i;
        ri2(q.r1, q.c1);
        q.r1--;
        q.c1--;
        ri2(q.r2, q.c2);
        q.r2--;
        q.c2--;
        queries.push_back(q);
    }
    FOR(i, 0, e){
        ans[i] = INF;
    }
    work(0, n - 1, 0, n - 1, queries);
    FOR(i, 0, e){
        if (ans[i] == INF){
            printf("%d\n", -1);
        }
        else{
            printf("%d\n", ans[i]);
        }
    }
}
/*
5 6
..X..
..X..
XX...
.....
XXXX.
1 1 2 2
1 1 3 3
2 2 2 2
3 3 5 5
1 2 5 5
1 3 5 5



2 1
..
..
2 2 2 2


*/
