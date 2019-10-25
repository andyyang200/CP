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

ll getOddIndex(ll x){
    ll i = (x + 1) / 2;
    if (i >= 1e18) {
		return (ll)1e18 + 1;
	}
    int k = 0;
    ll maxi = 0;
    while(maxi < i){
        if (k >= 63) break;
        maxi += (1LL << k);
        if (maxi < i){
            k += 2;
        }
    }
    if (k >= 62){
		return (ll)1e18 + 1;
    }
    return (1LL << (k + 1)) - 1 - (maxi - i);
}
ll getEvenIndex(ll x){
    ll i = x / 2;
    if (i >= 1e18) {
		return (ll)1e18 + 1;
	}
    int k = 1;
    ll maxi = 0;
    while(maxi < i){
        if (k >= 63) break;
        maxi += (1LL << k);
        if (maxi < i){
            k += 2;
        }
    }
    if (k >= 62){
		return (ll)1e18 + 1;
    }
    return (1LL << (k + 1)) - 1 - (maxi - i);
}


int main(){
    ll a, b;
    cin >> a >> b;
    ll odd1 = -1;
    ll odd2 = -1;
    ll even1 = -1;
    ll even2 = -1;
    ll l = 1;
    ll r = 1e18 + 1;
    while(l <= r){
        ll m = (l + r) / 2;
        ll odd = m * 2 - 1;
        if(getOddIndex(odd) >= a){
            odd1 = odd;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    l = 1;
    r = 1e18 + 1;
    while(l <= r){
        ll m = (l + r) / 2;
        ll odd = m * 2 - 1;
        if(getOddIndex(odd) <= b){
            odd2 = odd;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    l = 1;
    r = 1e18 + 1;
    while(l <= r){
        ll m = (l + r) / 2;
        ll even = m * 2;
        if(getEvenIndex(even) >= a){
            even1 = even;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    l = 1;
    r = 1e18 + 1;
    while(l <= r){
        ll m = (l + r) / 2;
        ll even = m * 2;
        if(getEvenIndex(even) <= b){
            even2 = even;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    ll ans = 0;
    if (odd1 <= odd2 && odd2 != -1){
        ll avg = (odd1 + odd2) / 2 % M;
        ll cnt = (odd2 - odd1) / 2 + 1;
        cnt %= M;
        ans += avg * cnt % M;
    }
    if (even1 <= even2 && even2 != -1){
        ll avg = (even1 + even2) / 2 % M;
        ll cnt = (even2 - even1) / 2 + 1;
        cnt %= M;
        ans += avg * cnt % M;
    }
    ans %= M;
    cout << ans << endl;
}


