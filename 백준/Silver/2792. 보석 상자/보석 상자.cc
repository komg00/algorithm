#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[300004], cnt, ret = 1e10;

int main() {
	cin >> n >> m;
	ll lo = 1, hi = 0, mid;
	
	for(ll i = 0; i < m; i++) {
		cin >> a[i];
		hi = max(hi, a[i]);
	}
	
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		cnt = 0;
		for(int i = 0; i < m; i++){
			cnt += a[i] / mid;
			if(a[i] % mid) cnt++;
		}
		if(cnt <= n) {
			ret = min(ret, mid);
			hi = mid -1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << endl;
}
