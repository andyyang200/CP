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
int a[14];
int b[14];
int main(void)
{
    ll ans = 0;
    FOR(i, 0, 14) cin>>a[i];
    FOR(i, 0, 14){
        memcpy(b, a, sizeof(a[0])*14);
        int x = b[i];
        b[i] = 0;
        FOR(j, 0, 14) b[j] += x / 14;
        x %= 14;
        FOR(j, i + 1, i + x + 1){
            b[j % 14]++;
        }
        ll y = 0;
        FOR(i, 0, 14){
            if (b[i] % 2 == 0) y += b[i];
        }
        ans = max(ans, y);
    }
    cout << ans << endl;
}

