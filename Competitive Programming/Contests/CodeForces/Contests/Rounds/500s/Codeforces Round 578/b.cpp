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
int h[1005];
int main(){
    int t;
    cin >> t;
    FOR(asd, 0, t){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        FOR(i, 0, n){
            scanf("%d", &h[i]);
        }
        bool can = true;
        FOR(i, 0, n - 1){
            int low = max(0, h[i + 1] - k);
            if (h[i] >= low){
                m += h[i] - low;
            }
            if (h[i] < low){
                m -= low - h[i];
            }
            if (m < 0){
                can = false;
            }
        }
        if (can){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

