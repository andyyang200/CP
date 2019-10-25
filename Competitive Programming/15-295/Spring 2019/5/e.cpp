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
int a[1000];
int b[1000];
int ans[105][105];
int main(){
    int n, m;
    cin >> n >> m;
    int totala = 0;
    int totalb = 0;
    FOR(i, 0, n){
        cin >> a[i];
        totala ^= a[i];
    }
    FOR(i, 0, m){
        cin >> b[i];
        totalb ^= b[i];
    }
    if (totala != totalb){
        cout << "NO" << endl;
        return 0;
    }
    ans[0][0] = a[0] ^ totalb ^ b[0];
    FOR(i, 1, n){
        ans[i][0] = a[i];
    }
    FOR(i, 1, m){
        ans[0][i] = b[i];
    }
    cout << "YES" << endl;
    FOR(i, 0, n){
        FOR(j, 0, m){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


}


