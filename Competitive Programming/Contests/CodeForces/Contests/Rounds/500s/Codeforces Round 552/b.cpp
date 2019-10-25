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

int n;
int a[1005];

int main(){
    scanf("%d", &n);
    FOR(i, 0, n){
        scanf("%d", a + i);
    }
    FOR(d, 0, 100 + 1){
        FOR(t, 1, 100 + 1){
            bool good = true;
            FOR(i, 0, n){
                if (abs(a[i] - t) == d || a[i] == t){

                }
                else{
                    good = false;
                }
            }
            if (good){
                cout << d << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

}


