//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

ll fastpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if (b % 2 == 0){
            ans *= ans;
            b /= 2;
        }
        else{
            ans *= a;
            b--;
        }
        ans %= M;
    }
    return ans;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    ll init = fastpow(2, n) - 1;
    ll timesadd = 1;
    FOR(i, 0, k){
        ll x = n * (fastpow(2, n) - 1) % M;
        init += x;
        init %= M;
    }
    cout << init << endl;
}
