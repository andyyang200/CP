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
int n;
int t[200005];
int cnt[200005];
int d;
bool check(int x){
    fill(cnt, cnt + n, 0);
    int distinct = 0;
    FOR(i, 0, x){
        if (cnt[t[i]] == 0) distinct++;
        cnt[t[i]]++;
    }
    if (distinct < d){
        return false;
    }
    FOR(i, 1, n){
        int j = i + x - 1;
        if (j >= n) break;
        int a = t[i - 1];
        int b = t[j];
        if (cnt[a] == 1){
            distinct--;
        }
        cnt[a]--;
        if (cnt[b] == 0) distinct++;
        cnt[b]++;
        if (distinct < d){
            return false;
        }
    }
    return true;
}
int main(){
    ri(n);
    set<int> s;
    FOR(i, 0, n){
        ri(t[i]);
        s.insert(t[i]);
    }
    d = s.size();
    vector<int> v;
    for(int x : s) v.push_back(x);
    sort(v.begin(), v.end());
    FOR(i, 0, n){
        t[i] = lower_bound(v.begin(), v.end(), t[i]) - v.begin();
    }
    int l = 1;
    int r = n;
    int ans = -1;
    while(l <= r){
        int m = (l + r) /2 ;
        if (check(m)){
            r = m - 1;
            ans = m;
        }
        else{
            l = m + 1;
        }
    }
    cout << ans << endl;
}
