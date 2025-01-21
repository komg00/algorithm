#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[52][52], day, sum, cnt;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[52][52];
bool isOpened;
queue<pair<int, int>> q;
vector<pair<int, int>> union_countries;
 
void go(int y, int x) {
	union_countries.clear();
	visited[y][x] = true;
	q.push({y, x});	
	union_countries.push_back({y, x});
	sum = a[y][x];
	cnt = 1;
	
	while(!q.empty()) {
		auto it = q.front();
		int cy = it.first;
		int cx = it.second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
			int diff = abs(a[ny][nx] - a[cy][cx]);
			if(diff < l || diff > r) continue;
				
			visited[ny][nx] = true;
			q.push({ny, nx});
			union_countries.push_back({ny, nx});
			sum += a[ny][nx];
			cnt++;
			isOpened = true;
		}
	}
	if(union_countries.size()) {
		int new_population = sum / cnt;
		for(auto it : union_countries) {
			a[it.first][it.second] = new_population;
		}
	}
} 

int main() {
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	while(true) {
		isOpened = false;
		memset(visited, false, sizeof(visited));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!visited[i][j]) go(i, j);
			}
		}
		if(!isOpened) break;
		day++;
	}
	cout << day;
	return 0;
}