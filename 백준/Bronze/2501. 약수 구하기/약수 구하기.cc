#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
vector<int> v;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		if (n % i == 0)
			v.push_back(i);
	}
	cout << v[k-1];
}