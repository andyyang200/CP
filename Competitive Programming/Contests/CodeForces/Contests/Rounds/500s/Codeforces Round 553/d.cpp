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
int a[100005];
int b[100005];
bool cmp(int i, int j){
    return a[j] + b[i] < b[j] + a[i];
}
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n){
        scanf("%d%d", &a[i], &b[i]);
    }
    vector<int> v;
    FOR(i, 0, n){
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    FOR(i, 0, n){
        ans += (ll)(i) * a[v[i]] + (ll)(n - i - 1) * b[v[i]];
    }
    cout << ans << endl;

}

