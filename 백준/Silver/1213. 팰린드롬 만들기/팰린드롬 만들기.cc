#include <bits/stdc++.h>
using namespace std;

string s;
string tmp;
int n, cnt[26], odd_cnt, one_cnt;

int main() {
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']++;
	}
	for(int i = 0; i < 26; i++) {
		if (cnt[i] % 2 != 0) {
			odd_cnt++;
			if (cnt[i] == 1) one_cnt++;
		}  
	}
	if (odd_cnt > 1) {
		cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}
	else {
		for(int i = 25; i >= 0; i--) {
			int length = cnt[i] / 2;
				tmp.insert(0, length, 'A' + i);
				tmp.insert(tmp.size(), length, 'A' + i);
			if(cnt[i] % 2 != 0) {
				tmp.insert(tmp.size() / 2, 1, 'A' + i);
			} 
		}
	}
	
	cout << tmp << "\n";
}