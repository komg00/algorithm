#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], ret, record, mx, result = 1e10, temp;

int main() {
	cin >> n >> m;
	ll lo = 1, hi = 0, mid;
	
	for(ll i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		record += a[i];
	}
	
	hi = record;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		temp = 0; // 초기화
    	ret = 0;  // 초기화

		for(int i = 0; i < n; i++) {
	        temp += a[i];
	        if(temp > mid) { // mid를 넘는 순간 새로운 그룹으로 나눔
	            ret++;
	            temp = a[i];
	        }
	    }
    	if(temp > 0) ret++; // 마지막 그룹 추가
		if(ret <= m) {
			result = min(result, mid);
			hi = mid -1;
			ret = 0;
		}else if(ret > m){
			lo = mid + 1;
			ret = 0;
		} 
	}
	if(mx > result) result = mx;
	cout << result << endl;
}
