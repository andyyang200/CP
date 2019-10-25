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

int a[20];
int blades[20];
bool can[1000005];
int main(){
    int t, n, m;
    scanf("%d%d%d", &t, &n, &m);


    FOR(asd, 0, t){
        set<int> answers;
        FOR(i, 1, m + 1){
            answers.insert(i);
        }
        FOR(i, 0, n){
            FOR(j, 0, 18){
                blades[j] = rand() % 16 + 2;
                printf("%d ", blades[j]);
            }
            int g = blades[0];
            FOR(j, 1, 18){
                g = __gcd(g, blades[j]);
            }
            printf("\n");
            fflush(stdout);
            int x = 0;
            FOR(i, 0, 18){
                scanf("%d", &a[i]);
                x += a[i];
            }
            FOR(i, 1, m+1){
                can[i] = false;
            }
            can[0] = true;
            FOR(i, 1, m + 1){
                FOR(j, 0, 18){
                    if (i - blades[j] >= 0 && can[i - blades[j]]){
                        can[i] = true;
                    }
                }
            }
            for(auto itr = answers.begin(); itr != answers.end();){
                if (*itr < x || !can[*itr - x]){
                    answers.erase(itr++);
                }
                else{
                    ++itr;
                }
            }
        }
        printf("%d\n", *answers.begin());
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if (res == -1){
            return 0;
        }
    }

}


