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


//---------------------------------------------------------------------------------------------------------------

int a[505][505];
int ans[500];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 0, n){
        FOR(j, 0, m){
            scanf("%d", &a[i][j]);
        }
    }
    int r = -1;
    FOR(i, 0, n){
        FOR(j, 1, m){
            if (a[i][j] != a[i][j - 1]){
                r = i;
                break;
            }
        }
    }
    if (r == -1){
        int x = 0;
        FOR(i, 0, n) {
            x ^= a[i][0];
        }
        if (x == 0){
            printf("NIE\n");
            return 0;
        }
        else{
            printf("TAK\n");
            FOR(i, 0, n){
                printf("1 ");
            }
            printf("\n");
            return 0;
        }
    }
    else{
        printf("TAK\n");
        int x = 0;
        FOR(i, 0, n){
            if (i != r){
                x ^= a[i][0];
            }
        }
        int rans = -1;
        FOR(j, 0, m){
            if ((x ^ a[r][j]) != 0){
                rans = j;
                break;
            }
        }
        ans[r] = rans;
        FOR(i, 0, n){
            printf("%d ", ans[i] + 1);
        }
        cout << endl;
    }
}


