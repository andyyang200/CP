#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int nb, ns, nc;
int pb, ps, pc;
ll r;
string s;
bool check(ll x){
    ll cntb = 0;
    ll cnts = 0;
    ll cntc = 0;
    FOR(i, 0, s.length()){
        if (s[i] == 'B'){
            cntb++;
        }
        else if (s[i] == 'S'){
            cnts++;
        }
        else{
            cntc++;
        }
    }
    cntb *= x;
    cnts *= x;
    cntc *= x;
    cntb = max(0LL, cntb - nb);
    cnts = max(0LL, cnts - ns);
    cntc = max(0LL, cntc - nc);
    ll price = 0;
    price += cntb * pb;
    price += cnts * ps;
    price += cntc * pc;
    return price <= r;
}
int main(){
    cin >> s;
    ri3(nb, ns, nc);
    ri3(pb, ps, pc);
    rll(r);
    ll l = 0;
    ll h = 1000000000000000LL;
    ll ans = -1;
    while(l <= h){
        ll m = (l + h) / 2;
        if (check(m)){
            ans = m;
            l = m + 1;
        }
        else{
            h = m - 1;
        }
    }
    cout << ans << endl;
}
