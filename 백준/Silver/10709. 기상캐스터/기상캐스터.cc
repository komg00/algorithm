#include <bits/stdc++.h>
using namespace std;
int h, w;
string s;

int main() {
	cin >> h >> w;
	vector<vector<int>> v(h,vector<int>(w,-1)); 
	
	for(int i = 0; i < h; i++) {
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == 'c') {
				v[i][j] = 0;
			}
		}
	}

	for(int k = 0; k < h; k++) {
		int ret = 0;
		for(int l = 0; l < w; l++) {
			if(v[k][l] != 0 && ret > 0) {
				v[k][l] = ret;
				ret++;
				
			} else if(v[k][l] == 0) {
				ret = 1;
			}
		}
	}
	
	for(int i = 0; i < h; i++) {
		for(auto num: v[i]) cout << num << " ";
		cout << endl;
	}
	
}