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

int n;
string s;
int px[200005];
int py[200005];
int sx[200005];
int sy[200005];
int tox[200];
int toy[200];
int x, y;
bool check(int m){
    FOR(i, 0, n){
        int j = i + m - 1;
        if (j >= n) break;
        int newx = x;
        if (i > 0) newx -= px[i - 1];
        newx -= sx[j + 1];
        int newy = y;
        if (i > 0) newy -= py[i - 1];
        newy -= sy[j + 1];
        int d = abs(newx) + abs(newy);
        if (m == d) return true;
        if (m > d && m % 2 == d % 2) return true;
    }
    m--;
    FOR(i, 0, n){
        int j = i + m - 1;
        if (j >= n) break;
        int newx = x;
        if (i > 0) newx -= px[i - 1];
        newx -= sx[j + 1];
        int newy = y;
        if (i > 0) newy -= py[i - 1];
        newy -= sy[j + 1];
        int d = abs(newx) + abs(newy);
        if (m == d) return true;
        if (m > d && m % 2 == d % 2) return true;
    }
    return false;
}

int bruteforce(){
    int ans = INF;
    FOR(i, 0, n){
        FOR(j, i, n){
            int m = j - i + 1;
            int newx = x;
            if (i > 0) newx -= px[i - 1];
            newx -= sx[j + 1];
            int newy = y;
            if (i > 0) newy -= py[i - 1];
            newy -= sy[j + 1];
            int d = abs(newx) + abs(newy);
            if (m == d) ans = min(ans, m);
            if (m > d && m % 2 == d % 2) ans = min(ans, m);
        }
    }
    if (ans == INF) ans = -1;
    return ans;
}

int mainsolve(){
    if (px[n - 1] == x && py[n - 1] == y){
        cout << 0 << endl;
        return 0;
    }
    if (abs(x) + abs(y) > 10000000){
        cout << -1 << endl;
        return 0;
    }

    int l = 0;
    int r = n;
    int ans = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if (check(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}

int main(){
    cin >> n;
    cin >> s;
    cin >> x >> y;

    tox['L'] = -1;
    tox['R'] = 1;
    toy['D'] = -1;
    toy['U'] = 1;

    px[0] = tox[s[0]];
    py[0] = toy[s[0]];
    FOR(i, 1, n){
        px[i] = px[i - 1] + tox[s[i]];
        py[i] = py[i - 1] + toy[s[i]];
    }
    sx[n - 1] = tox[s[n - 1]];
    sy[n - 1] = toy[s[n - 1]];
    RFOR(i, n - 2, -1){
        sx[i] = sx[i + 1] + tox[s[i]];
        sy[i] = sy[i + 1] + toy[s[i]];
    }
    if (px[n - 1] == x && py[n - 1] == y){
        cout << 0 << endl;
        return 0;
    }
    if (abs(x) + abs(y) > 10000000){
        cout << -1 << endl;
        return 0;
    }

    cout << mainsolve() << endl;
    cout << bruteforce() << endl;
}


