#include <bits/stdc++.h>
using namespace std;
unsigned long long temp, cnt, n;

int main() {	
	while(cin >> n) {
		cnt = 1;
		temp = 1;
		while(temp % n != 0) {
			cnt++;
			temp = (temp * 10 + 1) %n;
		}
		cout << cnt << "\n";
	}	
}