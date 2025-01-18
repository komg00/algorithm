#include <bits/stdc++.h>
using namespace std;
int n, m, n1, n2, cnt, mx;
vector<int> adj[100004];
int visited[100004], arr[100004];

int dfs(int here) {	
	visited[here] = 1;
	int cnt = 1;
	for(int there : adj[here]) {
		if (visited[there]) continue;
		cnt += dfs(there);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		adj[n2].push_back(n1);
	}
	
	for(int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		arr[i] = dfs(i);
		mx = max(arr[i], mx);
	}
	
	for(int i = 1; i <= n; i++) {
		if (arr[i] == mx) cout << i << " ";
	}
	return 0;
}