#include<bits/stdc++.h>
using namespace std;
int a, b, c;

long long modular(int a, int b) {
	long long result = 1;
	long long x = a % c; 
	
	while (b > 0) {
		if(b % 2 == 1) {
			result = (result * x) % c;
		}
		x = (x * x) % c;
		b = b/2;
	}
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;
	cout << modular(a, b);
}