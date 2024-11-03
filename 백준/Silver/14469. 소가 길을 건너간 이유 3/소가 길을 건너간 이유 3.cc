#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sum, a, b, ret, j;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	while(j < n) {
		// 합이 first보다 작을 때 
		if(v[j].first >= ret) {
			ret = v[j].first;
			ret += v[j].second;
		}
		
		// 합이 first보다 클 때
		else if(v[j].first < ret) {
			ret += v[j].second;
		} 
		j++;
	}
	cout << ret;
}