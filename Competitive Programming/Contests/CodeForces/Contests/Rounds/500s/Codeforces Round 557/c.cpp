#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[300005];
int f[300005];
int l[300005];
bool check(int a, int b){
    if (f[a] == -1 || f[b] == -1) return true;
    return f[a] > l[b];
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        f[i] = -1;
        l[i] = -1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &x[i]);
        x[i]--;
    }
    for(int i = 0; i < k; i++){
        l[x[i]] = i;
    }
    for(int i = k - 1; i >= 0; i--){
        f[x[i]] = i;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if (f[i] == -1){
            ans++;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if (check(i, i + 1)) ans++;
    }
    for(int i = 1; i < n; i++){
        if (check(i, i - 1)) ans++;
    }
    cout << ans << endl;
}

