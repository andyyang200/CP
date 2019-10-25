#include <bits/stdc++.h>
using namespace std;
int lim[100005];
int main(){
    int n, h, m;
    scanf("%d%d%d", &n, &h, &m);
    for(int i = 1; i <= n; i++)
        lim[i] = h;
    for(int i = 0; i < m; i++){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        for(int j = l; j <= r; j++){
            lim[j] = min(lim[j], x);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += lim[i] * lim[i];
    }
    cout << ans << endl;
}

