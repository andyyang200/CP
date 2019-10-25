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
int n;
int a[200005];
int b[200005];
int loc[200005];

int main(){
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
        loc[a[i]] = i;
    }
    FOR(i, 0, n){
        scanf("%d", &b[i]);
    }
    FOR(i, 0, n){
        b[i] = loc[b[i]];
    }
    int maxremoved = -1;
    FOR(i, 0, n){
        int ans = 0;
        if (b[i] > maxremoved){
            ans = b[i] - maxremoved;
        }
        maxremoved = max(maxremoved, b[i]);
        cout << ans << " ";
    }
    cout << endl;

}


