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
int x1, y1, x2, y2;
int vmax, t;
int vx, vy;
int wx, wy;

bool check(ld x){ // can we use x time
    ld dx, dy;
    if (x < t){
        dx = vx * x;
        dy = vy * x;
    }
    else{
        dx = vx * t + wx * (x - t);
        dy = vy * t + wy * (x - t);
    }
    dx += x1;
    dy += y1;
    ld tx = abs(x2 - dx);
    ld ty = abs(y2 - dy);
    ld dis = sqrt(tx * tx + ty * ty);
    return (ld)vmax * x >= dis;

}

int main(){
    ri2(x1, y1);
    ri2(x2, y2);
    ri2(vmax, t);
    ri2(vx, vy);
    ri2(wx, wy);
    ld l = 0;
    ld r = 1000000000;
    ld ans = -1;
    FOR(i, 0, 100){
        ld m = (l + r) / 2;
        if (check(m)){
            ans = m;
            r = m;
        }
        else{
            l = m;
        }
    }
    printf("%.9Lf\n", ans);
}
