#include <bits/stdc++.h>
using namespace std;
int n, m, max_safe_zone = 0;
int dy[4] = {1, 0, -1, 0};  
int dx[4] = {0, 1, 0, -1}; 
bool visited[10][10];
int a[10][10], temp[10][10];
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(temp[ny][nx] == 0 && !visited[ny][nx]) {
			temp[ny][nx] = 2;
			dfs(ny, nx);
		}
	}
}

int calculate_safe_zone() {
	memset(visited, 0, sizeof(visited));
	memcpy(temp, a, sizeof(a));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && temp[i][j] == 2) {
				dfs(i, j);
			}
		}
	}
	
	int ret = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(temp[i][j] == 0) {
				ret++;
			}
		}
	}
	return ret;
}

void combi(vector<pair<int, int>> v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = i + 1; j < v.size(); j++) {
			for(int k = j + 1; k < v.size(); k++) {
				a[v[i].first][v[i].second] = 1;
				a[v[j].first][v[j].second] = 1;
				a[v[k].first][v[k].second] = 1;
				
				max_safe_zone = max(max_safe_zone, calculate_safe_zone());
				
				a[v[i].first][v[i].second] = 0;
				a[v[j].first][v[j].second] = 0;
				a[v[k].first][v[k].second] = 0;
			}
		}
	}	
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) v.push_back({i, j});
		}
	}
	
	combi(v); 
	cout << max_safe_zone << "\n";
}