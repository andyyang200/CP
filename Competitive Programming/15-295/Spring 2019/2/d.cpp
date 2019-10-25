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
string s;
int a[100005];
int p[100005];
int getSum(int l, int r){
    int ans = p[r];
    if (l > 0) ans -= p[l - 1];
    return ans;
}
int main(){
    cin >> s;
    int n = s.length();
    FOR(i, 0, n - 1){
        if (s[i] == s[i + 1]){
            a[i]++;
        }
    }
    p[0] = a[0];
    FOR(i, 1, n){
        p[i] = p[i - 1] + a[i];
    }
    int q;
    cin >> q;
    FOR(t, 0, q){
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        cout << getSum(l, r - 1) << endl;
    }
}


