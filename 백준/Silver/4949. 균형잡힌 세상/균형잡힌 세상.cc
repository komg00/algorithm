#include <bits/stdc++.h>
using namespace std;

string s;
bool flag;

int main() {
	while(true) {
		getline(cin, s);
		flag = true;
		if (s == ".") break;
		
		stack<char> stk;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '(' || s[j] == '[') stk.push(s[j]);
			else if(s[j] == ')') {
				if(stk.size() && stk.top() == '(') stk.pop();
				else flag = false;
			}
			else if(s[j] == ']') {
				if(stk.size() && stk.top() == '[') stk.pop();
				else flag = false;
			}
		}
		if(stk.size()) flag = false;
		if(flag) cout << "yes" << "\n";
		else cout << "no" << "\n";
		
	}
    return 0;
}