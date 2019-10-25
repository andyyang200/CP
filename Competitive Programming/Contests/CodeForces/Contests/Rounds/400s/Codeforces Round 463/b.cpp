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

int f(int x){
    int ans = 1;
    while(x > 0){
        int y = x % 10;
        if (y > 0) ans *= y;
        x /= 10;
    }
    return ans;
}
int g[1000001];
void calc(int n){
    if (n < 10){
        g[n] = n;
    }
    else{
        g[n] = g[f(n)];
    }
}
int p[1000001][10];
int main(void)
{
    FOR(i, 0, 1000001){
        calc(i);
    }
    FOR(i, 1, 10){
        p[0][i] = (g[0] == i);
        FOR(j, 1, 1000001){
            p[j][i] = p[j - 1][i] + (g[j] == i);
        }
    }
    int q;
    cin >> q;
    FOR(i,0 , q){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int ans = p[r][k] - p[l - 1][k];
        cout << ans << endl;
    }
}
