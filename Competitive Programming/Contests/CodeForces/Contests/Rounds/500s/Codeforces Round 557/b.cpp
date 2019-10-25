#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int b[51][51];
int ans1[51][51];
int ans2[51][51];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &b[i][j]);
            ans1[i][j] = min(a[i][j], b[i][j]);
            ans2[i][j] = max(a[i][j], b[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i > 0 && ans1[i][j] <= ans1[i - 1][j]){
                cout << "Impossible" << endl;
                return 0;
            }
            if (j > 0 && ans1[i][j] <= ans1[i][j - 1]){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;




}
