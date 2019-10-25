#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];

int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int x = 0; x < n; x++){
		cin >> a[x];
	}
	sort(a, a + n);
	int ans = 0;
	for (int x = 0; x < n; x++){
		int cnt = 0;
		for (int j = x; j < n; j++){
			if (a[j] - a[x] <= k){
				cnt++;
			}
		}
		if (cnt > ans){
			ans = cnt;
		}
	}
	cout << ans << endl;
}