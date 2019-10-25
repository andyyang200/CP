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
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int ans[200005];
int main(){
    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    FOR(i, 0, n){
        if (i % 2 == 0){
            ans[i] = 2 * i + 1;
            ans[i + n] = 2 * i + 2;
        }
        else{
            ans[i] = 2 * i + 2;
            ans[i + n] = 2 * i + 1;
        }
    }
    FOR(i, 0, 2 * n){
        cout << ans[i] << " ";
    }
    cout << endl;
}
