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
int x[100005];
int y[100005];
int main(void)
{
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) cin >> x[i];
    FOR(i, 0, m) cin >> y[i];
    int a = 0;
    int b = 0;
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n || j < m){
        while(a == 0 || a < b){
            a += x[i++];
        }
        while(b == 0 || b < a){
            b += y[j++];
        }
        if (a == b){
            ans++;
            a = 0;
            b = 0;
        }
    }
    cout << ans << endl;
}
