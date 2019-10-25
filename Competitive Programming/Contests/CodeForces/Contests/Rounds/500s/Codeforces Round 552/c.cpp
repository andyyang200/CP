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

int d[]={0, 1, 2, 0, 2, 1, 0};
int a[3];
int t[3];
int main(){
    FOR(i, 0, 3){
        cin >> a[i];
    }
    int x = 0;
    FOR(i, 0, 7){
        memcpy(t, a, 3 * sizeof(int));
        int weeks = min(a[0] / 3, min(a[1] / 2, a[2] / 2));
        int ans = 7 * weeks;
        t[0] -= 3 * weeks;
        t[1] -= 2 * weeks;
        t[2] -= 2 * weeks;
        int j = i;
        while(true){
            if (t[d[j]] == 0) break;
            else{
                t[d[j]]--;
                ans++;
            }
            j = j + 1;
            j %= 7;
        }
        x = max(x, ans);
    }
    cout << x << endl;
}


