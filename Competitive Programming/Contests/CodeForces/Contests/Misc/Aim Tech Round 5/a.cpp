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

char grid[200][200];

int main() {
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> grid[i][j];
        }
    }
    int a, b, c, d;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (grid[i][j] == 'B'){
                a = i;
                b = j;
            }
        }
    }
    RFOR(i, n - 1, -1) {
        RFOR(j, m - 1, -1) {
            if (grid[i][j] == 'B'){
                c = i;
                d = j;
            }
        }
    }
    cout << (a + c) / 2 + 1 << " " << (b + d) / 2 + 1 << endl;
}
