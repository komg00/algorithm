#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> v;

int main() {
	while(true) {
		cin >> n;
		if(n == -1) break;
		cnt = 0;
		v.clear();
		for(int i = 1; i < n; i++) {
			if (n % i == 0) {
				cnt += i;
				v.push_back(i);
			}
		}
		if (n == cnt) {
			int length = v.size();
			cout << n << " = ";
			for (int i = 0; i < length - 1; i++) {
				cout << v[i] << " + ";
			}
			cout << v[length-1] << "\n";
		} else
			cout << n << " is NOT perfect.\n";
	}
}