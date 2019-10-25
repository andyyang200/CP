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
int n;
int query(int l, int r){
    printf("%d %d ", 1, r - l + 1);
    printf("%d ", 1);
    for(int i = l; i <= r; i++){
        printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; test++){
        int n;
        scanf("%d", &n);
        int l = 2;
        int r = n;
        int maxd = query(2, n);
        int farthest = -1;
        while(l < r){
            int m = (l + r) / 2;
            int x = query(l, m);
            if (x == maxd){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        farthest = l;
        printf("%d %d ", 1, n - 1);
        printf("%d ", farthest);
        for(int i = 1; i <= n; i++){
            if (i != farthest){
                printf("%d ", i);
            }
        }
        printf("\n");
        fflush(stdout);
        int x;
        cin >> x;
        printf("-1 %d\n", x);
        fflush(stdout);

    }

}

