#include <bits/stdc++.h>
using namespace std;
int n, m, ret, cheese;
int dy[4] = {1, 0, -1, 0}; 
int dx[4] = {0, 1, 0, -1};
int a[104][104];
bool visited[104][104];
int cnt;
vector<pair<int,int>> v;
 
void dfs(int y, int x) {
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(!visited[ny][nx]) {
			if(a[ny][nx] == 0) dfs(ny, nx);
			else if(a[ny][nx] == 1) {
				if(find(v.begin(), v.end(), make_pair(ny, nx)) == v.end()) {
					v.push_back({ny, nx});
				} 
			}
		} 
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	while(true) {
		memset(visited, false, sizeof(visited));
		v.clear();
		
		dfs(0, 0);
		
		if (v.empty()) break;
		
		cheese = v.size();
		for(auto it : v) {
			a[it.first][it.second] = 0;
		}
		ret++;
	}
	
	cout << ret << "\n";
	cout << cheese << "\n";
}