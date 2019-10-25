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


bool removed[1005];

int main(){
    int n, m;
    cin >> n >> m;
    if (m == 0){
        cout << 1 << endl;
        return 0;
    }
    int nodes = n - m;
    for(int i = 1; i < n; i += 2){
        if (m == 0) break;
        removed[i] = true;
        m--;
    }
    FOR(i, 0, n){
        if (m == 0) break;
        if (!removed[i]){
            removed[i] = true;
            m--;
        }
    }
    int edges = 0;
    FOR(i, 0, n){
        int j = (i + 1) % n;
        if (!removed[i] && !removed[j]) edges++;
    }
    cout << nodes - edges << endl;
}
