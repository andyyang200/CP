#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[100005];
int b[100005];
ll p[100005];
ll query(int a, int b){
    ll ret = p[b];
    if (a > 0) ret -= p[a - 1];
    return ret;
}
int main(void)
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];
    if (b[0] == 0) p[0] = a[0];
    FOR(i, 1, n){
        if (b[i] == 0)p[i] += a[i];
        p[i] += p[i - 1];
    }
    ll ans = 0;
    FOR(i, 0, n){
        int j = i + m - 1;
        if (j >= n) break;
        ans = max(ans, query(i, j));
    }
    FOR(i, 0, n){
        if (b[i] == 1) ans += a[i];
    }
    cout << ans << endl;
}


