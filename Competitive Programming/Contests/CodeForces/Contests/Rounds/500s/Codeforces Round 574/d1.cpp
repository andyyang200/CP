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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define M 998244353

string a[100005];
ll sum[25];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < a[i].length(); j++){
            int d = a[i][a[i].length() - j - 1] - '0';
            sum[2 * j] += (ll)n * d;
            sum[2 * j] %= M;
            sum[2 * j + 1] += (ll)n * d;
            sum[2 * j + 1] %= M;
        }
    }
    ll ans = 0;
    ll pow = 1;
    for(int i = 0; i < 25; i++){
        ans += pow * sum[i] % M;
        ans %= M;
        pow *= 10;
        pow %= M;
    }
    cout << ans << endl;

}
