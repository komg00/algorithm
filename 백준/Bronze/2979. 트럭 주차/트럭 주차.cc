#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v(100, 0);
int main() {
	int a, b, c, n, m;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> n >> m;
		for (int i = n; i < m; i++) {
			v[i]++;
		}
	}
	int count_a = count(v.begin(), v.end(), 1);
	int count_b = count(v.begin(), v.end(), 2);
	int count_c = count(v.begin(), v.end(), 3);
	
	cout << (count_a *a) + (count_b * 2 * b)+ (count_c * 3*c);
	
}
