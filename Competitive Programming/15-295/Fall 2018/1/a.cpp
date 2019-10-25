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
//---------------------------------------------------------------------------------------------------------------
int a[100005];
ll b[100005];
int n;
bool test(int x, int y) {
    ll d = a[y] - a[x];
    if (d % abs(y - x) != 0) return false;
    d /= abs(y - x);
    FOR(i, 0, n) {
        b[i] = a[x] + (i - x) * d;
    }
    int cnt = 0;
    FOR(i, 0, n) {
        if ((ll)a[i] != b[i]) cnt++;
    }
    return cnt <= 3;
}
int main(){
    cin >> n;
    FOR(i, 0, n) {
        scanf("%d", &a[i]);
    }
    if (n <= 5) {
        FOR(i, 0, n) {
            if (i >= 2) cout << a[0] + (ll)i * (a[1] - a[0]) << " ";
            else cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }
    FOR(i, 0, 5) {
        FOR(j, 1, 6) {
            if (i + j < n) {
                if (test(i, i + j)) {
                    FOR(i, 0, n) {
                        cout << b[i] << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}
