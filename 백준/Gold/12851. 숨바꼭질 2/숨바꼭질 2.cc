#include <bits/stdc++.h>
using namespace std;
int n, k, cnt[100001], visited[100001];
queue<int> q;

int main() {
	cin >> n >> k;
	visited[n] = 1;
	cnt[n] = 1;
	q.push(n);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int next : {x-1, x+1, x*2}) {
			if(0 <= next && next <= 100000) {
				if(!visited[next]) {
					q.push(next);
					visited[next] = visited[x] + 1;
					cnt[next] += cnt[x];
				} else if(visited[next] == visited[x] + 1) { 
				 	cnt[next] += cnt[x];
				}	
			}
		}
	}
	cout << visited[k] - 1<< "\n";
	cout << cnt[k] << "\n";
}