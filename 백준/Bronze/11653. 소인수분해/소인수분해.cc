#include <bits/stdc++.h>
using namespace std;

int n, temp, i;

int main() {
	cin >> n;
	temp = n;
	i = 2;
	while(temp > 1) {
		if(temp % i == 0) {
			cout << i << "\n";
			temp = temp / i;
			i = 2;
			continue;
		}
		i++;
	}

}