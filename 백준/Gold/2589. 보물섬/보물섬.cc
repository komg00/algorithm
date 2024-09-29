#include <bits/stdc++.h>
using namespace std;
int y, x, n, m, qy, qx, visited[54][54], result = -1;
queue<pair<int, int>> q;
vector<int> b;
char a[54][54];
string s;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1; 
	q.push({y, x});
	while(q.size())  {
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if(visited[ny][nx]) continue;
			if(a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			result = max(result, visited[ny][nx]);
			q.push({ny, nx});
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'L') bfs(i, j);
		}
	}
	cout << result - 1 << "\n";

	return 0;
}
