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
int arr[200005];
int n;
int main(){
    ri(n);
    FOR(i, 0, n){
        ri(arr[i]);
        if (arr[i] > 0) arr[i] = 1;
        if (arr[i] < 0) arr[i] = -1;
    }
    ll a = 0;
    ll b = 0;
    ll c = 0;
    int na = 0;
    int nc = 1;
    int prod = 1;
    FOR(i, 0, n){
        if (arr[i] == 0){
            na = 0;
            nc = 1;
            prod = 1;
        }
        else{
            prod *= arr[i];
            if (prod > 0){
                c += nc;
                a += na;
                nc++;
            }
            else{
                c += na;
                a += nc;
                na++;
            }

        }
    }
    b = (ll)n * (n - 1) / 2 + n - a - c;
    cout << a << " " << b << " " << c << endl;

}
