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
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int main(){
    int n, l, r;
    ri(n);
    ri(l);
    ri(r);
    ll a = 0;
    FOR(i, 0, l){
        a += (1 << i);
    }
    FOR(i, 0, n - l) a++;
    ll b = 0;
    FOR(i, 0, r){
        b += (1 << i);
    }
    FOR(i, 0, n - r){
        b += (1 << (r - 1));
    }
    cout << a << " " << b << endl;
}
