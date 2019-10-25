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
int main(){
    int t;
    cin >> t;
    for(int asd = 0; asd < t; asd++){
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        while(n > 0){
            if (n % k == 0) {
                n /= k;
                ans++;
                continue;
            }
            ll t = (n / k) * k;
            ans += n - t;
            n = t;
        }
        cout << ans << endl;
    }
}
