#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, v_sum;
vector<int> v;

int main() {
	cin >> m >> n;
	for(int i = m; i <= n; i++) {
		cnt = 0;
		if(i == 1) continue;
		for(int j = 2; j < i; j++) {
			if(i % j == 0) cnt++;
		}
		if(cnt == 0) {
			v_sum += i;
			v.push_back(i);
		}
	}
	if (v_sum == 0) cout << -1;
	else {
		cout << v_sum << "\n";
		cout << v[0] << "\n";
	}
	
}