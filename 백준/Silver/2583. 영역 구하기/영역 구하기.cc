#include <bits/stdc++.h>
using namespace std;

int m, n, k, a[101][101], visited[101][101], width, ret;
vector<int> v;
int left_x, left_y, right_x, right_y;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x) {
	visited[y][x] = 1;
	width++;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
		    continue;
		} 
		if(!visited[ny][nx] && a[ny][nx] == 0) {
			dfs(ny, nx);
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		cin >> left_x >> left_y >> right_x >> right_y;
		for(int i = n-right_y ; i < n-left_y; i++) {
			for(int j = left_x; j < right_x; j++) {
				a[i][j]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && a[i][j] == 0) {	
				width = 0;			
				dfs(i, j); ret++; 
				v.push_back(width);
			}
		}
	}
	cout << ret << "\n";
	sort(v.begin(), v.end());
	for(auto i : v) 
		cout << i << " ";
	cout << "\n";
  
}