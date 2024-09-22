#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, a[54][54], row, col, ret;
bool visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x) {
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 ||  nx < 0 || ny >= m || nx >= n) continue;
 		if(a[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}
int main() {
	cin >> t;
	for(int test = 0; test < t; test++) {
		ret = 0;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		cin >> n >> m >> k;
		for(int i = 0; i < k; i++) {
			cin >> row >> col;
			a[col][row] = 1;
		}
		
		for(int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(a[i][j] == 1 && !visited[i][j]) {
					dfs(i, j); 
					ret++;
				}
			}
		}
		cout << ret << "\n";
	}	
}