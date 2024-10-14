#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] + a[j] == m) {
				cnt++;
			}
		}
	}
	cout << cnt;
}