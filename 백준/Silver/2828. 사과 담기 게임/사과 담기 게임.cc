#include <bits/stdc++.h>
using namespace std;
int n, m, j, cnt, temp, l;

int main() {
	cin >> n >> m >> j;
	l = 1;
	for(int i = 0; i < j; i++) {
		cin >> temp;
		int r = l + m - 1; 
		if(temp >= l && temp <= r) continue; 
		else if(temp < l) { 
			cnt += l - temp;
			l = temp;
		} else if(temp > r) { 
			cnt += temp - r; 
			l = temp - m + 1;
		}
	}
	
	cout << cnt << "\n";
}