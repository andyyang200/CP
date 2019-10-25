#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[105];
pii overlap(pii a, pii b){
    return {max(a.first, b.first), min(b.second, a.second)};
}
int main(){
    int q;
    scanf("%d", &q);
    FOR(i, 0, q){
        int n, k;
        scanf("%d%d", &n, &k);
        FOR(i, 0, n){
            scanf("%d", &a[i]);
        }
        pii p = {-INF, INF};
        bool bad = false;
        FOR(i, 0, n){
            p = overlap(p, {a[i] - k, a[i] + k});
            if (p.second < p.first){
                bad = true;
                break;
            }
        }
        if (bad || p.second <= 0){
            cout << "-1" << endl;
        }
        else{
            cout << p.second << endl;
        }
    }
}

