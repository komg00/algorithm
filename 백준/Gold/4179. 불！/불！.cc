#include <bits/stdc++.h>
using namespace std;
int r, c, ret, result;
char a[1004][1004]; 
bool visited[1004][1004];
int dy[4] = {1, 0, -1, 0}; 
int dx[4] = {0, 1, 0, -1}; 
queue<pair<int, int>> J;
queue<pair<int, int>> F;

bool isValid(int ny, int nx){
	return ny >= 0 && nx >= 0 && ny < r && nx < c && a[ny][nx] == '.' && !visited[ny][nx];
}

int bfs() {
	while(!J.empty()) {		
		int fire_size = F.size();
		while(fire_size--) {
			int fy = F.front().first;
			int fx = F.front().second;
			F.pop();
			for(int d = 0; d < 4; d++){
				int ny = fy + dy[d];
				int nx = fx + dx[d];
				if(isValid(ny, nx)) {
					a[ny][nx] = 'F';
					F.push({ny, nx});
				}
			}
		}
		
		int jihoon_size = J.size();
		while(jihoon_size--) {
			int jy = J.front().first;
			int jx = J.front().second;
			J.pop();
			for(int d = 0; d < 4; d++){
				int ny = jy + dy[d];
				int nx = jx + dx[d];
				// 탈출 성공 
				if (ny < 0 || nx < 0 || ny >= r || nx >= c) return ret + 1;
				if(isValid(ny, nx) && !visited[ny][nx]) {
					visited[ny][nx] = true;
					J.push({ny, nx});
				}
			}
		}
		ret++;
	}
	return -1;
} 

int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'J') J.push({i, j});
			else if(a[i][j] == 'F') F.push({i, j});
		}
	}
	
	result = bfs();
	if(result == -1){
		cout << "IMPOSSIBLE";
	} else {
		cout << result << "\n";
	}
}