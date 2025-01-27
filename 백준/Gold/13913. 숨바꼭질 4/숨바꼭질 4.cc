#include <bits/stdc++.h>
using namespace std;
int n, k, cnt[100001], visited[100001];
int v[100001];
vector<int> path;
queue<int> q;

int main() {
	cin >> n >> k;
	visited[n] = 1;
	q.push(n);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int next : {x-1, x+1, x*2}) {
			if(0 <= next && next <= 100000) {
				if(!visited[next]) {
					q.push(next);
					visited[next] = visited[x] + 1;
					v[next] = x;
				} 
			} 
		}
	}
	cout << visited[k] - 1<< "\n";
	
	for(int cur = k; cur != n; cur = v[cur]) {
		path.push_back(cur);
	}
	path.push_back(n);
	for(int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}