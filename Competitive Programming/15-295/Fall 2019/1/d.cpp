#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int n, k, x;
int cnt[2024];
int cnt2[2024];
int main(){
    ri3(n, k, x);
    FOR(i, 0, n){
        int a;
        ri(a);
        cnt[a]++;
    }
    FOR(asd, 0, k){
        FOR(i, 0, 1025){
            cnt2[i] = cnt[i];
            cnt[i] = 0;
        }
        int tot = 0;
        FOR(i, 0, 1025){
            int change = -1;
            if (tot % 2 == 0){
                change = (cnt2[i] + 1) / 2;
            }
            else{
                change = cnt2[i] / 2;
            }
            cnt[i ^ x] += change;
            cnt[i] += cnt2[i] - change;
            tot += cnt2[i];
        }

    }
    int a = 2025;
    int b = 0;
    FOR(i, 0, 1025){
        if (cnt[i] > 0){
            a = min(a, i);
            b = max(b, i);
        }
    }
    printf("%d %d\n", b, a);
}

