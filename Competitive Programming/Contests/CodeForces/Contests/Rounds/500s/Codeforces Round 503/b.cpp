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

int n;
int p[1005];
bool visited[1005];
int main() {
    int n;
    cin >> n;
    FOR(i, 0, n) {
        cin >> p[i];
        p[i]--;
    }
    FOR(i, 0, n) {
        fill(visited, visited + n, false);
        int j = i;
        while(!visited[j]) {
            visited[j] = true;
            j = p[j];
        }
        cout << j + 1 << " ";
    }
    cout << endl;
}
