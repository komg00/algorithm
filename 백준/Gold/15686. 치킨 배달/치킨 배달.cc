#include <bits/stdc++.h>
using namespace std;

int n, m, result = 987654321;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<vector<int>> chickenList;
int a[54][54];

void combi(int start, vector<int> b) {

	if(b.size() == m) {
		chickenList.push_back(b);
		return;
	}
	
	for(int i = start + 1; i < chicken.size(); i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}	
	return;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				home.push_back({i, j});
			}
			if (a[i][j] == 2) {
				chicken.push_back({i, j});
			}
		}
	}
	
	vector<int> b;
	combi(-1, b);
    for (vector<int> cList : chickenList) {
  		int ret = 0; 
    	for(pair<int, int> h : home) {
    		int chi_dist = 987654321;
    		for(int ch : cList) {
    			int dist = abs(h.first - chicken[ch].first) + abs(h.second - chicken[ch].second);
    			chi_dist = min(chi_dist, dist);
			}
    		ret += chi_dist;
		}
		result = min(result, ret);
	}
	cout << result << "\n";
	return 0;
}