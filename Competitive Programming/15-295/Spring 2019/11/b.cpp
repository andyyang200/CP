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

int ans[300005];
int main(){
    set<int> s;
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 1, n + 1){
        s.insert(i);
    }

    FOR(i, 0, m){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        auto itr = s.lower_bound(l);
        while(itr != s.end() && *itr <= r){
            if (*itr != x){
                ans[*itr] = x;
                s.erase(itr++);
            }
            else{
                ++itr;
            }
        }
    }
    FOR(i, 1, n + 1){
        cout << ans[i] << " ";
    }
    cout << endl;
}


