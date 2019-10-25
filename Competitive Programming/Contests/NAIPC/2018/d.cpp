#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int a[100005];
bool seen[100005];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        seen[a[i]] = true;
    }
    set<int> s;
    for(int i = 1; i <= n; i++){
        if (!seen[i]) s.insert(i);
    }
    for(int i = 0; i < m; i++){
        while(!s.empty() && *(s.begin()) < a[i]){
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
        cout << a[i] << endl;
    }
    while(!s.empty()){
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
}
