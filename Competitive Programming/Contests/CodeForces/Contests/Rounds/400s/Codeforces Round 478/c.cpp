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

int a[200005];
ll p[200005];
int get(int a, int b){
    ll ans = p[b];
    if (a > 0)
        ans -= p[a - 1];
    return ans;
}
int main(void)
{
    int n, q;
    cin >> n >> q;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    p[0] = a[0];
    FOR(i, 1, n){
        p[i] = p[i - 1] + a[i];
    }
    int j = 0;
    int d = 0;
    FOR(i, 0, q){
        ll k;
        scanf("%lld", &k);
        if (d + k < a[j]){
            d += k;
            continue;
        }
        else{
            k -= a[j] - d;

        }
    }
}

