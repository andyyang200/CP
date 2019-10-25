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
const int MN = 4e3 + 10;
string a, b;
int n, m, k;
int ans = 0;
void Try(int p1, int p2) {
  int head = 0, tail = 0, diff = 0;
  while (a[p1 + head] && b[p2 + head]) {
    if (a[p1 + head] != b[p2 + head]) diff++;
    head++;
    while (diff > k) {
      if (a[p1 + tail] != b[p2 + tail]) diff--;
      tail++;
    }
    ans = max(ans, head - tail);
  }
}
int main() {
    ans = 0;
    scanf("%d", &k);
    cin >> a >> b;
    n = a.length();
    m = b.length();

    Try(0, 0);
    FOR(i, 1, m - 1)
      Try(0, i);
    FOR(i, 1, n - 1)
      Try(i, 0);
    printf("%d\n", ans);

}
