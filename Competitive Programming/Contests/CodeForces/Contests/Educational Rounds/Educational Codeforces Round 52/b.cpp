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
    ll n, m;
    cin >> n >> m;
    ll minans = max(0LL, n - 2 * m);
    ll maxans = 0;
    RFOR(i, n, -1){
        int unisolated = n - i;
        ll edges = (ll)unisolated * (unisolated - 1) / 2;
        if (edges >= m){
            maxans = i;
            break;
        }
    }
    cout << minans << " " << maxans;
}

