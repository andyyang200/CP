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
int r[105];
int main(){
    int n;
    ri(n);
    ld R;
    cin >> R;
    FOR(i, 0, n) ri(r[i]);
    sort(r, r + n);
    vector<vector<int>> ans;
    FOR(nr, 1, 5005){
        RFOR(i, n - 1, -1){
            vector<int> v;
            ld sum = 0;
            FOR(j, 0, nr){
                sum += (ld)1.0 / r[i];
                v.push_back(r[i]);
            }
            sum = 1.0 / sum;
            while (R >= sum - 0.01){
                R -= sum;
                ans.push_back(v);
            }
            if (abs(R) <= 0.01){
                break;
            }
        }
        if (abs(R) <= 0.01){
            break;
        }
    }
    printf("%d\n", ans.size());
    FOR(i, 0, ans.size()){
        printf("%d ", ans[i].size());
        for(int x : ans[i]){
            printf("%d ", x);
        }
        printf("\n");
    }
}

