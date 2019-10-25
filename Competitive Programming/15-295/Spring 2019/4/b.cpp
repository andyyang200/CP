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
int p[100005];
bool visited[100005];
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    FOR(i, 0, n){
        fill(visited, visited + n, false);
        int x = i;
        while(!visited[x]){
            visited[x] = true;
            x = p[x];
        }
        printf("%d ", x + 1);
    }
    cout << endl;
}

