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

int h[200005];
int hcnt[200005];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int maxh = 0;
    FOR(i, 0, n){
        scanf("%d", &h[i]);
        maxh = max(maxh, h[i]);
        hcnt[h[i]]++;
    }
    RFOR(i, maxh, 0){
        hcnt[i - 1] += hcnt[i];
    }
    ll sum = 0;
    int ans = 0;
    RFOR(i, maxh, -1){
        if (hcnt[i] == n) break;
        if (sum + hcnt[i] > k){
            ans++;
            sum = 0;
        }
        sum += hcnt[i];
    }
    if (sum) ans++;

    cout << ans << endl;
}


