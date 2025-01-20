#include <bits/stdc++.h>
using namespace std;
int node, k, num, level;
vector<int> tree[12];
int a[1025];

void print(int lo, int hi, int level) {
	if(lo > hi) return;
	if(lo == hi) {
		tree[level].push_back(a[lo]);
		return;
	}
	int mid = (lo + hi) / 2;
	tree[level].push_back(a[mid]);
	print(lo, mid - 1, level + 1);
	print(mid + 1, hi, level + 1);
	return;
}

int main() {
	cin >> k;
	node = pow(2, k) - 1;
	for(int i = 0; i < node; i++) {
		cin >> a[i];
	}
	print(0, node, 1);
	for(int i = 1; i <= k; i++) {
		for(int j : tree[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
	
}