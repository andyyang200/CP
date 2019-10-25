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
int cnt[100][100];
char a[100][100];
int main(void)
{
    int n, k;
    cin >> n >> k;
    int m = n;
    FOR(i, 0, n){
        FOR(j, 0, m){
            scanf(" %c", &a[i][j]);
        }
    }
    FOR(i, 0, n - k + 1){
        FOR(j, 0, m){
            bool ship = true;
            FOR(x, i, i + k){
                if (a[x][j] == '#'){
                    ship = false;
                }
            }
            if (ship){
                FOR(x, i, i + k){
                    cnt[x][j]++;
                }
            }
        }
    }

    FOR(i, 0, n){
        FOR(j, 0, m - k + 1){
            bool ship = true;
            FOR(x, j, j + k){
                if (a[i][x] == '#'){
                    ship = false;
                }
            }
            if (ship){
                FOR(x, j, j + k){
                    cnt[i][x]++;
                }
            }
        }
    }
    int ans = 0;
    FOR(i, 0, n){
        FOR(j,0, m){
            ans = max(ans, cnt[i][j]);
        }
    }
    FOR(i, 0, n){
        FOR(j ,0, m){
            if (cnt[i][j] == ans){
                printf("%d %d\n", i + 1, j + 1);
                return 0;
            }
        }
    }

}


