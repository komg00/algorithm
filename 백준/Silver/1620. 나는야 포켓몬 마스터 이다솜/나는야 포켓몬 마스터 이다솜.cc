#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, var;
map<string, int> mp;
string a[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s;
		a[i + 1] = s;
		mp[s] = i + 1;
	}
	for(int i = 1; i <= m; i++) {
		cin >> var;
		if (atoi(var.c_str()) == 0) { // 문자인 경우
			cout << mp[var] << "\n";
		}
		else {  // 숫자인 경우 
			cout << a[atoi(var.c_str())] << "\n";
		}
	}
}