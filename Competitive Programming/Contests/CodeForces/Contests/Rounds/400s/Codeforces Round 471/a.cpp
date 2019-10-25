//Andy Yang
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

int main(void)
{
    int h, m;
    cin >> h >> m;
    int x, d, c, n;
    cin >> x >> d >> c >> n;
    int wait;
    if (h >= 20){
        wait = 0;
    }
    else{
        wait = (20 - h - 1) * 60 + 60 - m;
    }
    ld ans = min(((x + wait * d + n - 1) / n) * 0.8 * c, (double)((x + n - 1) / n) * c);
    printf("%.9Lf\n", ans);
}

