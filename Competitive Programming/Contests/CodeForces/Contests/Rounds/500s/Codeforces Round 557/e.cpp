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

int a[51];
int n;
int main(){
    scanf("%d", &n);
    set<int> s;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == a[0]) cnt++;
    }
    if (cnt > n / 2)
        cout << "Bob" << endl;
    else{
        cout << "Alice" << endl;
    }

}

