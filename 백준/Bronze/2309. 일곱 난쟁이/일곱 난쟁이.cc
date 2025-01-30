#include <bits/stdc++.h>
using namespace std;
int num, a[12],sum;
vector<int> v;

int main() {
	
	for(int i = 0; i < 9; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	do{
		sum = 0;
		for(int i = 0; i < 7; i++) {
			sum += v[i];
		}
		
		if (sum == 100) {
			for(int i = 0; i < 7; i++) {
				cout << v[i] << "\n";
			}
			break;
		}
	} while(next_permutation(v.begin(), v.end()));
}