#include <bits/stdc++.h>
using namespace std;

int n, cnt, i;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(cnt < n) {
		i++;
		string s = to_string(i); 
		if(s.find("666") != string::npos) cnt++;
	}
	cout << i << endl;

    return 0;
}