#include <bits/stdc++.h>
using namespace std;
int n, c, num, idx, k;
vector<int> a, b;
map<int, vector<int>> myMap; 

int main() {
	cin >> n >> c;
	for(int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	while(idx < n) {
		int cnt = count(a.begin(), a.end(), a[k]);
		if(find(myMap[cnt].begin(), myMap[cnt].end(), a[k]) != myMap[cnt].end()) { // 같은 경우 제 
			k++;
			continue;
		} 
		else {
			myMap[cnt].push_back(a[k]);
			idx += cnt;
			k++;
		}
	}
	for(auto iter = myMap.rbegin(); iter != myMap.rend(); ++iter) {
		for(auto &elem: iter->second) {
			for(int i = 0; i < iter-> first; i++) {
				b.push_back(elem);
			}
		}
	}
	for(auto em: b) cout << em << " ";
}