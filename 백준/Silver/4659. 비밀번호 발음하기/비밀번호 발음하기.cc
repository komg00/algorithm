#include<bits/stdc++.h>
using namespace std;

string s;
bool cond1, cond2, cond3;
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
	while (true) {
		cin >> s;
		if(s == "end") break;
		
		cond1 = false;
        cond2 = true;
        cond3 = true;
        
		for(char a : s) {
			if(find(begin(vowel), end(vowel), a) != end(vowel)) {
				cond1 = true;
				break;
			}
		}
	
		for(int i = 2; i < s.length(); i++) {
			if((find(begin(vowel), end(vowel), s[i]) != end(vowel) && 
				find(begin(vowel), end(vowel), s[i-1]) != end(vowel) && 
				find(begin(vowel), end(vowel), s[i-2]) != end(vowel)) || 
				(find(begin(vowel), end(vowel), s[i]) == end(vowel) && 
				find(begin(vowel), end(vowel), s[i-1]) == end(vowel) && 
				find(begin(vowel), end(vowel), s[i-2]) == end(vowel))) {
				cond3 = false;
				break;
			} 
		}
 		
		for(int i = 1; i < s.length(); i++) {
			if(s[i-1] == s[i] && s[i] != 'e' && s[i] != 'o') {			
				cond3 = false;
				break;	
			}
		}
		
		if(cond1 && cond2 && cond3) {
			cout << "<" << s << "> is acceptable." << "\n"; 
		}
		else cout << "<" << s << "> is not acceptable." << "\n"; 
	}
	return 0;
	
}