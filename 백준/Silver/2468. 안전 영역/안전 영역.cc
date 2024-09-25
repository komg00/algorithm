#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], cnt, max_cnt, height, visited[101][101], max_elm; 
int dy[4] = {-1, 0, 1, 0};  
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(visited[ny][nx] == 0 && a[ny][nx] > height) {
			dfs(ny, nx);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (max_elm < a[i][j]) max_elm = a[i][j];
		}
	}

	while(height < max_elm) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));	
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(a[i][j] > height && !visited[i][j]) {
					dfs(i, j); cnt++;
				}
			}
		}
		if (max_cnt <= cnt) max_cnt = cnt;
		height++;	
	}
	cout << max_cnt << "\n";
}