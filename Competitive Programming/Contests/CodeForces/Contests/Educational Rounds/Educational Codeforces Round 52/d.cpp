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
// 1 : knight, 2 : rook, 3 : bishop



int n;
int a[11][11];
int dx1[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy1[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool check(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}
vector<pii> moves1(int i, int j){
    vector<pii> ans;
    FOR(k, 0, 8){
        int newi = i + dx1[k];
        int newj = j + dy1[k];
        if (check(newi, newj)){
            ans.push_back({newi, newj});
        }
    }
    return ans;
}
vector<pii> moves2(int i, int j){
    vector<pii> ans;
    FOR(r, 0, n){
        FOR(c, 0, n){
            if (r == i && c == j) continue;
            if (r == i || c == j){
                ans.push_back({r, c});
            }
        }
    }
    return ans;
}
vector<pii> moves3(int i, int j){
    vector<pii> ans;
    FOR(r, 0, n){
        FOR(c, 0, n){
            if (r == i && c == j) continue;
            if (abs(r - i) == abs(c - j)){
                ans.push_back({r, c});
            }
        }
    }
    return ans;
}


int d[11][11][11][11][4];
bool visited[11][11];
pii loc[105];
void bfs(int type, int starti, int startj){
    queue<pii> q;
    FOR(i, 0, n){
        FOR(j, 0, n){
            visited[i][j] = false;
            d[starti][startj][i][j][type] = INF;
        }
    }
    q.push({starti, startj});
    visited[starti][startj] = true;
    d[starti][startj][starti][startj][type] = 0;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        vector<pii> moves;
        if (type == 1){
            moves = moves1(r, c);
        }
        else if (type == 2){
            moves = moves2(r, c);
        }
        else{
            moves = moves3(r, c);
        }
        for(pii move : moves){
            int r2 = move.first;
            int c2 = move.second;
            if (!visited[r2][c2]){
                visited[r2][c2] = true;
                q.push(move);
                d[starti][startj][r2][c2][type] = d[starti][startj][r][c][type] + 1;
            }
        }
    }
}
pii dp[205][5];
int main(){
    cin >> n;
    FOR(i, 0, n){
        FOR(j, 0, n){
            scanf("%d", &a[i][j]);
            loc[a[i][j]] = {i, j};
        }
    }
    FOR(i, 1, n * n + 1){
        bfs(1, loc[i].first, loc[i].second);
        bfs(2, loc[i].first, loc[i].second);
        bfs(3, loc[i].first, loc[i].second);
    }
    dp[1][1] = {0, 0};
    dp[1][2] = {0, 0};
    dp[1][3] = {0, 0};
    FOR(i, 2, n * n + 1){
        FOR(t1, 1, 4){
            dp[i][t1] = {INF, INF};
            FOR(t2, 1, 4){
                int dis = dp[i - 1][t2].first + d[loc[i - 1].first][loc[i - 1].second][loc[i].first][loc[i].second][t1] + (t1 != t2 ? 1 : 0);
                int r = dp[i - 1][t2].second + (t1 != t2 ? 1 : 0);
                dp[i][t1] = min(dp[i][t1], {dis, r});
            }
        }
    }
    pii ans = {INF, INF};
    ans = min(ans, dp[n * n][1]);
    ans = min(ans, dp[n * n][2]);
    ans = min(ans, dp[n * n][3]);
    cout << ans.first << " " << ans.second;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60
61 62 63 64 65 66 67 68 69 70
71 72 73 74 75 76 77 78 79 80
81 82 83 84 85 86 87 88 89 90
91 92 93 94 95 96 97 98 99 100

*/


