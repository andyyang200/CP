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
int a[200005];
int main(){
    cin >> n;
    ll sum = 0;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int max2 = 0;
    int max1 = 0;
    FOR(i, 0, n){
        if (a[i] >= max2){
            max1 = max2;
            max2 = a[i];
        }
        else if (a[i] >= max1){
            max1 = a[i];
        }
    }
    vector<int> ans;
    FOR(i, 0, n){
        int t = max2;
        if (a[i] == t) t = max1;
        if (2 * t == sum - a[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int x : ans) printf("%d ", x + 1);
    printf("\n");

}


