#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//---------------------------------------------------------------------------------------------------------------

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            FOR(k, j + 1, n) {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

