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
char grid[2001][2001];
int n, m;
int r, c;
int x, y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}
int dis[2001][2001];
int main(){
    ri2(n, m);
    ri2(r, c);
    r--;
    c--;
    ri2(x, y);
    x = min(x, n * m);
    y = min(y, n * m);
    FOR(i, 0, n){
        FOR(j, 0, m){
            cin >> grid[i][j];
            dis[i][j] = INF;
        }
    }
    deque<pii> d;
    d.push_back({r, c});
    dis[r][c] = 0;
    while(!d.empty()){
        int i = d.front().first;
        int j = d.front().second;
        d.pop_front();
        FOR(k, 0, 4){
            int i2 = i + dx[k];
            int j2 = j + dy[k];
            if (valid(i2, j2) && dis[i2][j2] == INF){
                if (i2 == i && j2 == j + 1){
                    dis[i2][j2] = dis[i][j] + 1;
                    d.push_back({i2, j2});
                }
                else{
                    dis[i2][j2] = dis[i][j];
                    d.push_front({i2, j2});
                }
            }
        }
    }
    int ans = 0;
    FOR(i, 0, n){
        FOR(j, 0, m){
            int right = dis[i][j];
            if (right == INF) continue;
            int left = right - j + c;
            if (left <= x && right <= y){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
/*
4 4
3 3
0 0
....
..*.
....
....
*/
