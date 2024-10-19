#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, num;
map<string, vector<string>> myMap;
string s, key;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m;
		cnt = 0;
		num = 1;
		for(int j = 0; j < m; j++) {
			cin >> s >> key;
			myMap[key].push_back(s);
		}
		
		for(auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
			num *= (iter->second.size() + 1);
		}
		
		cnt += num;
		cout << cnt - 1 << "\n";
		myMap.clear();
	}
}