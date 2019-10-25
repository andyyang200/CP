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

int par[1234567], dist[1234567], used[1234567];

const int MAXM = 20 * (1 << 20);
int root(int a) {
	if (a == par[a]) return a;
	return par[a] = root(par[a]);
}
pair<char, pair<int, int>> A[MAXM], B[MAXM];
int e;
const int MAXC = 1 << 16;
int cnt[MAXC], pos[MAXC];
void radixSort() {
	memset(cnt, 0, sizeof(cnt));
	unsigned int mask = MAXC - 1;
	for (int i = 0; i < e; ++i) ++cnt[A[i].first & mask];
	pos[0] = 0;
	for (int i = 1; i < MAXC; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
	for (int i = 0; i < e; ++i) B[pos[A[i].first & mask]++] = A[i];
	for (int i = 0; i < e; ++i) A[i] = B[i];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(used, -1, sizeof(used));
    memset(dist, -1, sizeof(dist));
    queue<int> Q;
    for (int i = 1; i <= m; ++i) {
        char str[25];
        scanf("%s", str);
        int v = 0;
        for (int j = 0; j < n; ++j)
            if (str[j] == '1') v |= 1 << j;
        Q.push(v);
        dist[v] = 0;
        used[v] = i;
    }
    e = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int k = 0; k < n; ++k) {
            int y = x ^ (1 << k);
            if (used[y] == -1) {
                used[y] = used[x];
                dist[y] = dist[x] + 1;
                Q.push(y);
            } else if (used[y] != used[x]) {
                int d = dist[x] + dist[y] + 1;
                A[e++] = {d, {used[x], used[y]}};
            }
        }
    }
    sort(A, A + e);
    for (int i = 1; i <= m; ++i) par[i] = i;
    int ans = 0;
    for (int j = 0; j < e; ++j) {
        int u = root(A[j].second.first), v = root(A[j].second.second);
        if (u == v) continue;
        par[u] = v;
        ans += A[j].first;
    }
    printf("%d\n", (m-1) * n - ans);
}
