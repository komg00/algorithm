#include <bits/stdc++.h>
using namespace std;

int main() {
	string temp;
	int n;
	vector<int> v(26, 0);
	bool isP = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v[temp[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if(v[i] >= 5) {
			cout<<(char) ('a'+i);
	 		isP = true;
		}
	}
	if (isP == false)
		cout << "PREDAJA";
}