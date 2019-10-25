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
int n;
int a[400005];
int cnt[400005];
int p[400005];
int query(int l, int r){
    int ans = p[r];
    if (l > 0){
        ans -= p[l - 1];
    }
    return ans;
}
int main(){
    ri(n);
    FOR(i, 0, n){
        ri(a[i]);
        cnt[a[i]]++;
    }
    p[0] = cnt[0];
    FOR(i, 1, 400005){
        p[i] = p[i - 1] + cnt[i];
    }
    ll ans = 0;
    sort(a, a + n);
    FOR(i, 0, n){
        if (i > 0 && a[i] == a[i - 1]){
            continue;
        }
        int x = a[i];
        ll v = 0;
        for(int j = x; j <= 200001; j += x){
            v += (ll)j * query(j, j + x - 1);
        }
        ans = max(ans, v);
    }
    cout << ans << endl;
}

