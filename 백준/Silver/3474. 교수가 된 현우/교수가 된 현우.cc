#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long t_cnt, f_cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		long long tnum = 1;
		long long fnum = 1;
		t_cnt, f_cnt = 0;
		while(tnum <= n) {
			tnum *= 2;
			t_cnt += n / tnum;
		}
		while(fnum <= n) {
			fnum *= 5;
			f_cnt += n / fnum;			
		}
		cout << min(t_cnt, f_cnt) << "\n";
	}
}