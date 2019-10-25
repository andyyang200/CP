//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int ans[1000005];

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    FOR(i, 0, n + 1){
        if (i * a <= n && (n - i * a) % b == 0){
            int j = (n - i * a) / b;
            int index = 0;
            FOR(x, 0, i){
                FOR(y, index, index + a - 1){
                    ans[y] = y + 1;
                }
                ans[index + a - 1] = index;
                index += a;
            }
            FOR(x, 0, j){
                FOR(y, index, index + b - 1){
                    ans[y] = y + 1;
                }
                ans[index + b - 1] = index;
                index += b;
            }
            FOR(i, 0, n){
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
            return 0;
        }
        if (i * a >= n) break;
    }
    cout << -1 << endl;
}

