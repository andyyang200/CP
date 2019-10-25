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
bool a[4][105];
int main(){
    int tests;
    scanf("%d", &tests);
    FOR(test, 0, tests){
        int A;
        scanf("%d", &A);
        FOR(i, 1, 200){ // reset
            a[1][i] = false;
            a[2][i] = false;
            a[3][i] = false;
        }
        FOR(i, 1, 200){
            bool done = false;
            while(!a[1][i] || !a[2][i]|| !a[3][i]){
                printf("%d %d\n", 2, i + 1);
                fflush(stdout);
                int x, y;
                scanf("%d%d", &x, &y);
                if (x == -1 && y == -1){
                    return 0;
                }
                if (x == 0 && y == 0){
                    done = true;
                    break;
                }
                else{
                    a[x][y] = true;
                }
            }
            if (done){
                break;
            }
        }
    }
}

