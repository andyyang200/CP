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
int numdigits(ll x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }
    return ans;
}
string pad(string s, int n){
    reverse(s.begin(), s.end());
    while(s.length() < n) s += "0";
    reverse(s.begin(), s.end());
    return s;
}
int common(string a, string b){
    int ans = 0;
    int x = 0;
    FOR(i, 0, a.length()){
        if (a[i] == b[i]){
            x++;
        }
        else{
            x = 0;
        }
        ans = max(ans, x);
    }
    return ans;
}
int dp[20][2][20];
int main(){
    int C;
    scanf("%d", &C);
    FOR(c, 0, C){
        int m, z, r;
        scanf("%d%d%d", &m, &z, &r);
        int n = numdigits(m);
        FOR(i, 0, 20){

        }
    }

}


