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
#define MAX 1000005
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int c[MAX];
int n, k;
int cnt[MAX];
int sieve[MAX];

void build(){
    FOR(i, 1, MAX){
        sieve[i] = i;
    }
    FOR(i, 2, MAX){
        if (sieve[i] != i){ // composite
            continue;
        }
        for(int j = 2 * i; j < MAX; j += i){ // prime
            sieve[j] = i;
        }
    }
}
bool done[1000005];
int main(){
    scanf("%d%d", &n, &k);
    FOR(i, 0, n){
        scanf("%d", &c[i]);
        if (c[i] == k){
            cout << "Yes" << endl;
            return 0;
        }
    }
    build();
    FOR(i, 0, n){
        int x = c[i];
        if (done[x]) continue;
        done[x] = true;
        while(x != 1){
            int p = sieve[x];
            int pcnt = 0;
            while(x % p == 0){
                x /= p;
                pcnt++;
            }
            cnt[p] = max(cnt[p], pcnt);
        }
    }
    int x = k;
    while(x != 1){
        int p = sieve[x];
        int pcnt = 0;
        while(x % p == 0){
            x /= p;
            pcnt++;
        }
        if (pcnt > cnt[p]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
