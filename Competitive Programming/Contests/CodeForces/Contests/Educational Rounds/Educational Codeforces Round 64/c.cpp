#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
multiset<int, greater<int>> s2;
int main(){
    int n, z;
    scanf("%d%d", &n, &z);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        s.insert(x);
        s2.insert(x);
    }
    int ans = 0;
    while(!s.empty()){
        int x = *s.begin();
        auto itr = s.lower_bound(x + z);
        if (itr == s.end()){
            break;
        }
        else{
            ans++;
            s.erase(itr);
            s.erase(*s.begin());
        }
    }
    int ans2 = 0;
    while(!s2.empty()){
        int x = *s2.begin();
        auto itr = s2.lower_bound(x - z);
        if (itr == s2.end()){
            break;
        }
        else{
            ans2++;
            s2.erase(itr);
            s2.erase(*s2.begin());
        }
    }
    cout << max(ans, ans2) << endl;
}
