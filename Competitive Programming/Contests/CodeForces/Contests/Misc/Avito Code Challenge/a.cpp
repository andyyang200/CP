    #include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
bool check(string s){
    FOR(i, 0, s.length()){
        if (s[i] != s[s.length() - 1 - i]){
            return false;
        }
    }
    return true;
}
int main(void)
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    FOR(i, 0, n){
        FOR(j, i, n){
            if (!check(s.substr(i, j - i + 1))){
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
}

