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
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int main(){
    int prod = 1;
    int n;
    ri(n);
    bool seenzero = false;
    ll ans = 0;
    FOR(i, 0, n){
        int x;
        ri(x);
        if (x < 0){
            ans += abs(-1 - x);
            prod *= -1;
        }
        else{
            ans += abs(1 - x);
        }
        if (x == 0){
            seenzero = true;
        }
    }
    if (prod == -1 && seenzero == false){
        ans += 2;
    }
    cout << ans << endl;
}
