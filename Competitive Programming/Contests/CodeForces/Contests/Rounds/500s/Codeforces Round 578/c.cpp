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

int main(){
    ll n, m, q;
    cin >> n >> m >> q;
    ll x = __gcd(n, m);
    FOR(i, 0, q){
        ll s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        s2--;
        e2--;
        if (s1 == 1){
            s2 /= (n / x);
        }
        else{
            s2 /= (m / x);
        }
        if (e1 == 1){
            e2 /= (n / x);
        }
        else{
            e2 /= (m / x);
        }
        if (s2 == e2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

