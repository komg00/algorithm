#include<bits/stdc++.h>
using namespace std;

int n;
string s, result;
vector<string> v;

void go() {
	while(true) {
		if(result.size() && result.front() == '0') {
			result.erase(0, 1);
		} else break;
	}
	if(result.size() == 0) result = "0";
	v.push_back(result);
	result = "";
}

bool cmp(string a, string b) {
	if(a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a < b;
}

int main() {
	cin >> n; 
	for(int i = 0; i < n; i++) {
		cin >> s;
		result = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 65) result += s[j];					
			else if(result.size()) go();
		}
		if(result.size()) go();
	}

	sort(v.begin(), v.end(), cmp);
	for(auto num : v) {
		cout << num << "\n";
	}
		
	return 0;
}