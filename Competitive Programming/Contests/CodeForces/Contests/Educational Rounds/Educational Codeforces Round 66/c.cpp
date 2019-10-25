
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
int a[200005];

int n, k;


int main(){
    int T;
    scanf("%d", &T);
    for(int test = 0; test < T; test++){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int j = k;
        int ans = 2000000000;
        int minpoint = -1;
        for(int i = 0; i + k < n; i++){
            int j = i + k;
            int x = (a[i] + a[j]) / 2;
            int d = max(x - a[i], a[j] - x);
            if (d < ans){
                ans = d;
                minpoint = x;
            }
        }
        cout << minpoint << endl;

    }
}
