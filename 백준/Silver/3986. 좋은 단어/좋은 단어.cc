#include<bits/stdc++.h>
using namespace std;
int n, ret;
string s;
char tmp;
stack<char> stk;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {	
		cin >> s;
			
		stk.push(s[0]);
		for(int j = 1; j < s.length(); j++) {
			if (!stk.empty()) {
				tmp = stk.top();				
				if(tmp == s[j]) {
					stk.pop();
				} else {
					stk.push(s[j]);
				}
			} else {
				stk.push(s[j]);
			}
		}
		
		if(stk.empty()) ret++;
		stk = stack<char>(); 
 	}
 	cout << ret << "\n";
}