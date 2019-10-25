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
int a[200005];
int ans[200005];
int main(){
    int n;
    ri(n);
    FOR(i, 0, n){
        ri(a[i]);
        a[i]--;
        if (a[i] <= i){
            cout << -1 << endl;
            return 0;
        }
    }
    fill(ans, ans + n, -1);
    ans[0] = 0;
    int cur = 1;
    FOR(i, 0, n){
        if (ans[i] == -1){
            ans[i] = cur++;
        }
        if (a[i] != n){
            if (ans[a[i]] != -1 && ans[a[i]] != ans[i]){
                cout << -1 << endl;
                return 0;
            }
            ans[a[i]] = ans[i];
        }
    }
    if (cur > 26){
        cout << -1 << endl;
        return 0;
    }
    FOR(i, 0, n){
        cout << (char)('a' + ans[i]);
    }
    cout << endl;
}

