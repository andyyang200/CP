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

bool done[200];
int last[200];
int cnt[200];

int main(){
    int t;
    cin >> t;
    FOR(i, 0, t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        fill(done, done + 200, false);
        fill(last, last + 200, -1);
        fill(cnt, cnt + 200, 0);
        FOR(i, 0, n) {
            char c = s[i];
            cnt[c]++;
            last[c] = i;
        }
        ll ans = 0;
        int start = 0;
        FOR(i, 0, n) {
            char c = s[i];
            if (done[c]) continue;
            done[c] = true;
            ans += cnt[c] * 5 * (last[c] - start - cnt[c] + 1);
            start += cnt[c];
        }
        cout << ans << endl;
    }
}

/*
2
6
AABABB
10
Ab9AAb2bC2
*/


