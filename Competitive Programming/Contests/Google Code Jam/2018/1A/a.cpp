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
int a[105][105];
int rcnt[105];
int ccnt[105];
void run(int test){
    int r, c, h, v;
    scanf("%d%d%d%d", &r, &c, &h, &v);
    FOR(i, 0, r){
        rcnt[i] = 0;
    }
    FOR(j, 0, c){
        ccnt[j] = 0;
    }
    int total = 0;
    FOR(i, 0, r){
        FOR(j, 0, c){
            char x;
            cin >> x;
            if (x == '@'){
                a[i][j] = 1;
                rcnt[i]++;
                ccnt[j]++;
                total++;
            }
            else{
                a[i][j] = 0;
            }
        }
    }
    if (total == 0){
        printf("Case #%d: POSSIBLE\n", test);
        return;
    }
    if (total % ((v + 1) * (h + 1)) != 0){
        printf("Case #%d: IMPOSSIBLE\n", test);
        return;
    }
    int cnt = 0;
    vector<int> rcut;
    vector<int> ccut;
    rcut.push_back(0);
    ccut.push_back(0);
    FOR(i, 0, r){
        cnt += rcnt[i];
        if (cnt == total / (h + 1)){
            rcut.push_back(i + 1);
            cnt = 0;
        }
        else if (cnt > total / (h + 1)){
            printf("Case #%d: IMPOSSIBLE\n", test);
            return;
        }
    }
    FOR(i, 0, c){
        cnt += ccnt[i];
        if (cnt == total / (v + 1)){
            ccut.push_back(i + 1);
            cnt = 0;
        }
        else if (cnt > total / (v + 1)){
            printf("Case #%d: IMPOSSIBLE\n", test);
            return;
        }
    }
    assert(rcut.size() == h + 2);
    assert(ccut.size() == v + 2);
    FOR(i, 0, rcut.size() - 1){
        FOR(j, 0, ccut.size() - 1){
            int cnt = 0;
            FOR(x, rcut[i], rcut[i + 1]){
                FOR(y, ccut[j], ccut[j + 1]){
                    cnt += a[x][y];
                }
            }
            if (cnt != total / ((v + 1) * (h + 1))){
                printf("Case #%d: IMPOSSIBLE\n", test);
                return;
            }
        }
    }

    printf("Case #%d: POSSIBLE\n", test);
    return;
}
int main(void)
{
    int tests;
    scanf("%d", &tests);
    FOR(test, 1, tests + 1){
        run(test);
    }
}


