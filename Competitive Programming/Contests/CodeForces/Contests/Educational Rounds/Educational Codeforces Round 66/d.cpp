
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
int a[300005];
ll s[300005];
int main(){
    int k, n;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    s[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        s[i] = a[i] + s[i + 1];
    }
    sort(s + 1, s + n);
    ll ans = s[0];
    for(int i = n - k + 1; i < n; i++){
        ans += s[i];
    }
    cout << ans << endl;

}
