#include <bits/stdc++.h>
using namespace std;
int n, p, d, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> v(n); 
	for(int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if(pq.size() > v[i].first) {
			pq.pop();
		}
	} 
	while(pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}
