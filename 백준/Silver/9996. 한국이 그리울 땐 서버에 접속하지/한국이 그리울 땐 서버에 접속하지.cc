#include <bits/stdc++.h>
using namespace std;
string s, pattern, pre, suf;
int n;

int main() {
	cin >> n;
	cin >> pattern;
	int pos = pattern.find("*");
	pre = pattern.substr(0, pos);
	suf = pattern.substr(pos+1);
	for (int i = 0; i < n; i++) {
		cin >> s;

		if (s.size() < pre.size() + suf.size()) {
			cout << "NE" << endl;
		} else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) {
					cout << "DA" << endl;
			}	
			else cout << "NE" << endl;	
		}
	}
	return 0;
}