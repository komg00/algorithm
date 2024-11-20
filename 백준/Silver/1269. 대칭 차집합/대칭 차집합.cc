#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, m, num, ret;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	ret = 0;
	for(int i = 0; i < n; i++) {
		cin >> num;
		mp[num] += 1; 
	}
	
	for(int i = 0; i < m; i++) {
		cin >> num;
		mp[num] += 1;
	}
	
	for(auto i : mp) {
		if (i.second == 1) {
			ret++;
		}
	}
	
	cout << ret;
}
