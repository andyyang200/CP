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


int a[100005];
int win[100005];
int loc[100005];
vector<int> edges[100005];
int main(){
    int n;
    cin >> n;

    FOR(i, 0, n){
        scanf("%d", &a[i]);
        loc[a[i]] = i;
    }
    FOR(i, 0, n){
        for(int j = i + a[i]; j < n; j += a[i]){
            if (a[j] > a[i]){
                edges[i].push_back(j);
            }
        }
        for(int j = i - a[i]; j >= 0; j -= a[i]){
            if (a[j] > a[i]){
                edges[i].push_back(j);
            }
        }
    }
    RFOR(i, n - 1, 0){
        win[loc[i]] = false;
        for(int j : edges[loc[i]]){
            if (!win[j]){
                win[loc[i]] = true;
                break;
            }
        }
    }
    FOR(i, 0, n){
        if (win[i]){
            cout << "A";
        }
        else{
            cout << "B";
        }
    }
    cout << endl;

}

