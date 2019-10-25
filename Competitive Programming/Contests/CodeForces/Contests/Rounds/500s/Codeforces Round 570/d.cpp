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
int a[200005];
bool seen[200005];
int main(){
    int q;
    scanf("%d", &q);
    FOR(i, 0, q){
        int n;
        scanf("%d", &n);
        fill(a, a + n + 1, 0);
        fill(seen, seen + n + 1, false);
        FOR(i, 0, n){
            int x;
            scanf("%d", &x);
            a[x]++;
        }
        sort(a, a + n + 1);
        int cnt = n;
        ll ans = 0;
        RFOR(i, n, -1){
            if(cnt > a[i]){
                cnt = a[i];
            }
            if (cnt <= a[i] && cnt >= 0){
                ans += cnt;
                cnt--;
            }
        }
        printf("%lld\n", ans);
    }
}
