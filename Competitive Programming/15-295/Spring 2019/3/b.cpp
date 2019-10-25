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
struct edge{
    int u, v;
    ld w;
};
edge edges[1005];
ld d[501];
int n, m;
int A, B;
bool negcycle;
void f(){
    FOR(i, 0, n){
        d[i] = INF;
    }
    negcycle = false;
    d[A] = 0;
    FOR(i, 0, n + 2){
        FOR(j, 0, m){
            int u = edges[j].u;
            int v = edges[j].v;
            ld w = edges[j].w;
            d[v] = min(d[v], d[u] + w);
        }
    }
    FOR(j, 0, m){

        int u = edges[j].u;
        int v = edges[j].v;
        ld w = edges[j].w;
        if (d[u] + w < d[v]) negcycle = true;
    }
}
bool check(ld avg){ // check answer is <= avg
    FOR(i, 0, m){
        edges[i].w -= avg;
    }

    f();
    FOR(i, 0, m){
        edges[i].w += avg;
    }
    return negcycle || d[B] <= 0;

}
int main(){
    int T;
    scanf("%d", &T);
    FOR(asd, 0, T){
        scanf("%d%d", &n, &m);
        FOR(i, 0, m){
            int w;
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &w);
            edges[i].u--;
            edges[i].v--;
            edges[i].w = w;
        }
        scanf("%d%d", &A, &B);
        A--;
        B--;
        f();
        if (d[B] == INF){
            cout << -1 << endl;
            continue;
        }
        ld l = 1;
        ld r = 100;
        ld ans = -1;
        FOR(xxx, 0, 105){
            ld m = (l + r) / 2;
            if (check(m)){
                ans = m;
                r = m;
            }
            else{
                l = m;
            }
        }
        printf("%.9Lf\n", ans);

    }
}


