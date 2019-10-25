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
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll k = sqrt(a + b);
        bool yes = true;
        if (a - b != 1){
            yes = false;
        }
        FOR(i, 2, k + 1){
            if ((a + b) % i == 0){
                yes = false;
                break;
            }
        }
        if (yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}


