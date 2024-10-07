#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv;
int k[5];
int a[20][5];
int asum, bsum, csum, dsum, esum, bestnum;
int bestsum = 10000;
vector<int> best;
vector<int> current;

int main() {
	cin >> n;
	cin >> k[0] >> k[1] >> k[2] >> k[3];
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
	
	for(int i = 0; i < (1 << n); i++) {
		asum = 0;
	 	bsum = 0; 
		csum = 0;
		dsum = 0;	
		esum = 0;
		current.clear();
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				asum += a[j][0];
				bsum += a[j][1];
				csum += a[j][2];
				dsum += a[j][3];
				esum += a[j][4];
				current.push_back(j+1);
			}
		}
		if(asum >= k[0] && bsum >= k[1] && csum >= k[2] && dsum >= k[3]) {
			if(bestsum > esum) {
				bestsum = esum;
				bestnum = i;
				best = current;
			} else if(bestsum == esum) {						
				if(current < best) {
					best = current;
				}
			}
		}	
	}
	
	if(bestsum == 10000) {
		cout << -1;
	} else {
		cout << bestsum << "\n";
		for(int x : best) {
			cout << x << " ";
		}
	}	
	return 0;
}