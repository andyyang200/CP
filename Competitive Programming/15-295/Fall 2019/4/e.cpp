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
int n, k;
int t[200005];
int d[200005];
int main(){
    ri2(n, k);
    multiset<pii> p;
    FOR(i ,0 ,n){
        ri(t[i]);
        ri(d[i]);
        p.insert({d[i], t[i]});
    }
    multiset<int> s;
    ll ans = 0;
    FOR(i, 0, n + 1){
        while(p.size() > 0 && p.begin()->first <= i){
            s.insert(p.begin()->second);
            p.erase(p.begin());
        }
        if (s.empty()){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans += *s.begin();
        s.erase(s.begin());
        if (i == k - 1){
            break;
        }
    }
    cout << ans << endl;

}
