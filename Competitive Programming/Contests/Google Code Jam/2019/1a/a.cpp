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

bool visited[25][25];
int n, m;

bool good(int r1, int c1, int r2, int c2){
    if (r1 == r2){
        return false;
    }
    if (c1 == c2){
        return false;
    }
    if (r1 - c1 == r2 - c2){
        return false;
    }
    if (r1 + c1 == r2 + c2){
        return false;
    }
    return true;
}
vector<pii> ans;
vector<pii> ret;
bool found;
void f(int r, int c){
    if (found){
        return;
    }
    if (ans.size() == n * m){
        ret = ans;
        found = true;
        return;
    }
    FOR(r2 , 0, n){
        FOR(c2, 0, m){
            if (!visited[r2][c2] && good(r, c, r2, c2)){
                visited[r2][c2] = true;
                ans.push_back({r2, c2});
                f(r2, c2);
                ans.pop_back();
                visited[r2][c2] = false;

            }
        }
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    FOR(test, 0, tests){
        scanf("%d%d", &n, &m);
        found = false;
        ans = vector<pii>();
        FOR(r, 0, n){
            FOR(c, 0, m){
                visited[r][c] = true;
                ans.push_back({r, c});
                f(r, c);
                ans.pop_back();
                visited[r][c] = false;
                if (found){
                    break;
                }
            }
            if (found){
                break;
            }
        }
        if (found){
            printf("Case #%d: POSSIBLE\n", test + 1);
            for(pii p : ret){
                printf("%d %d\n", p.first + 1, p.second + 1);
            }
        }
        else{
            printf("Case #%d: IMPOSSIBLE\n", test + 1);
        }
    }

}

