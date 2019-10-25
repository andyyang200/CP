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


int main() {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    FOR(i, 0 ,k) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        int d1, d2;
        if (fa < a) d1 = a;
        else if (fa > b) d1 = b;
        else d1 = fa;
        int ans = abs(fa - d1) + abs(fb - d1) + abs(tb - ta);
        if (ta == tb) {
            ans = abs(fa - fb);
        }
        cout << ans << endl;
    }
}
