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
int cnt[100005];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int x = (n + 1) / 2;
    int ans = 0;
    for(int i = 0; i <= k; i++){
        int take = min(x, cnt[i] / 2);
        ans += 2 * take;
        x -= take;
        cnt[i] -= 2 * take;
    }
    for(int i = 0; i <= k; i++){
        if (cnt[i] && x){
            x--;
            ans++;
        }
    }
    cout << ans << endl;
}
