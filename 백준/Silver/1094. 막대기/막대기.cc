#include <bits/stdc++.h>
using namespace std;
int n, cnt, i;
int main() {
	
	cin >> n;
	while(n >= (1 << i)) {
		if (n & (1 << i)) {
			cnt++;
		} 
		i++;
	}
	cout << cnt;
}