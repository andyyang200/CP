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

int n;
int a[100005];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if (a[i] == 1 && a[i + 1] == 2){ // circle triangle
            ans += 3;
            if (i >= 1 && a[i - 1] == 3){
                ans--;
            }
        }
        else if (a[i] == 1 && a[i + 1] == 3){// circle square
            ans += 4;
        }
        else if (a[i] == 2 && a[i + 1] == 1){// triangle circle
            ans += 3;
        }
        else if (a[i] == 2 && a[i + 1] == 3){// triansle square
            cout << "Infinite" << endl;
            return 0;
        }
        else if (a[i] == 3 && a[i + 1] == 1){// square circle
            ans += 4;
        }
        else if (a[i] == 3 && a[i + 1] == 2){// square triangle
            cout << "Infinite" << endl;
            return 0;
        }
    }

    cout << "Finite" << endl;
    cout << ans << endl;
}
