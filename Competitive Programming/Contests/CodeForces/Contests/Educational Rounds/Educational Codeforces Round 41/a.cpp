#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[1005];
int main(void)
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        a[c]++;
        int x = 12039123;
        for(int j = 1; j <= n; j++){
            x = min(x, a[j]);
        }
        ans += x;
        for(int j = 1; j <= n; j++){
            a[j] -= x;
        }
    }
    cout << ans << endl;
}



