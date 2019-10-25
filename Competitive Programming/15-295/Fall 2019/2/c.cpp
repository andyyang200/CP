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

int n, l, v1, v2, k;

bool check(ld t){ // use t time?
    ld curt = 0;
    ld curd = 0;
    for(int i = 0; i < n; i += k){
        if (i + k >= n){
            curt += (l - curd) / v2;
            break;
        }

        ld r = l - curd;
        ld x = ((t - curt) * v1 * v2 - v2 * r) /(v1 - v2);
        x = min(x, r);
        ld dt = 2 * x / (v1 + v2);
        curt += dt;
        curd += dt * v1;
        if (curd >= l){
            break;
        }
    }
    return curt <= t;
}

int main(){
    ri3(n, l, v1);
    ri2(v2, k);
    ld lo = 0;
    ld hi = l;
    ld ans = -1;
    FOR(i, 0, 100){
        ld m = (lo + hi) / 2;
        if (check(m)){
            ans = m;
            hi = m;
        }
        else{
            lo = m;
        }
    }
    printf("%.9Lf\n", ans);
}
