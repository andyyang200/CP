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
bool prime[100];
int f(ll l, ll r){
    ll a = 1;
    ll b = 1e9;
    ll ans1 = -1;
    while(a <= b){
        ll m = (a + b) / 2;
        if (m * m < l){
            a = m + 1;
        }
        else{
            b = m - 1;
            ans1 = m;
        }
    }
    a = 1;
    b = 1e9;
    ll ans2 = -1;
    while(a <= b){
        ll m = (a + b) / 2;
        if (m * m > r){
            b = m - 1;;
        }
        else{
            a = m + 1;
            ans2 = m;
        }
    }
    db(ans1);
    db(ans2);
    return ans2 - ans1 + 1;
}
int main(void)
{
    FOR(i, 2, 61) prime[i] = true;
    FOR(i, 2, 61){
        if (!prime[i]) continue;
        for(int j = i + i; j <= 61; j += i){
            prime[j] = false;
        }
    }
    set<ll> s;
    FOR(i, 2 ,1000001){
        ll j = i;
        FOR(k, 2, 60){
            if (1000000000000000000LL / (ll)j < (ll)i)break;
            j *= i;
            if (k % 2 == 1){
                s.insert(j);
                //db(j);
            }
        }
    }
    vector<ll> v;
    sort(v.begin(), v.end());
    FOREACH(itr, s){
        v.push_back(*itr);
    }
    int q;
    cin >> q;
    FOR(i, 0, q){
        ll l, r;
        cin >> l >> r;
        db2(l, r);
        ll ans = upper_bound(v.begin(), v.end(), r)- lower_bound(v.begin(), v.end(), l);
        db(ans);
        ans += f(l, r);
        cout << ans << endl;

    }

}

