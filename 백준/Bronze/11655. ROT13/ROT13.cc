#include <bits/stdc++.h>
using namespace std;
string s, ret;
int main() {
	getline(cin, s);
	for(int i = 0; i < s.length(); i++) {
		if (97 <= s[i] && s[i] <= 122) {  // 소문자 
			if(s[i] + 13 > 122) {
				cout << (char)(s[i] - 26 + 13);
			}
			else
				cout << (char)(s[i] + 13);
		}
		else if (65 <= s[i] && s[i] <= 90) { // 대문자 
			if(s[i] + 13 > 90) {
				cout << (char)(s[i] - 26 + 13);
			}
			else
				cout << (char)(s[i] + 13);
		}
		else {
			cout << s[i];
		}
	}
}