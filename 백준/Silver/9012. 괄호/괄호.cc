#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		stack<char> stk;
		for(int j = 0; j < s.size(); j++) {
			
			if(s[j] == '(') stk.push(s[j]);
			else if(s[j] == ')') {
				if(stk.size() && stk.top() == '(') stk.pop();
				else stk.push(s[j]);
			}
		}
		
		if(stk.size()) cout << "NO" << "\n";
		else cout << "YES" << "\n";
		
	}
    return 0;
}