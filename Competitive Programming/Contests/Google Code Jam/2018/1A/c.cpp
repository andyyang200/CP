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
typedef pair<ld, ld> pdd;

vector<pdd> v;
int w[105];
int h[105];
int main(void)
{
    int tests;
    scanf("%d", &tests);
    FOR(test, 1, tests + 1){
        int n, p;
        scanf("%d%d", &n, &p);
        double original = 0;
        FOR(i, 0, n){
            scanf("%d%d", &w[i], &h[i]);
            original += 2 * w[i] + 2 * h[i];
        }
        double a = 2 * min(w[0], h[0]);
        double b = 2 * sqrt(w[0] * w[0] + h[0] * h[0]);
        double x = p - original;
        if (a > original){
            printf("Case #%d: %.9f\n", test, original);
            continue;
        }
        if (x > n * b){
            printf("Case #%d: %.9f\n", test, n * b + original);
            continue;
        }
        double s = floor(x / a);
        if (s * a <= x && s * b >= x){
            printf("Case #%d: %.9f\n", test, x + original);
            continue;
        }
        else{
            printf("Case #%d: %.9f\n", test, s * b + original);
            continue;
        }
    }
}


