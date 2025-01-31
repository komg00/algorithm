#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	getline(cin, s);
	
	for(int i = 0; i < s.size(); i++) {
		int k = s[i];
		
		if((k >= 65 && k <= 77) || (k >= 97 && k <= 109)) {
			cout << (char)(s[i] + 13);
		}
		else if((k >= 78 && k <= 90) || (k >= 110 && k <= 122)) {
			cout << (char)(s[i] - 13);
		}
		else cout << s[i];
	}
}
