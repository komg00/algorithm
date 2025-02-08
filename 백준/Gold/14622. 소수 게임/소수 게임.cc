#include <bits/stdc++.h>
using namespace std;
int n, a, b;
long long scoreA, scoreB;
map<int, int> mp;
priority_queue<int, vector<int>, greater<int>> pqA, pqB;

bool isPrime(int a) {
	if (a < 2) return false;
	for (int i = 2; i * i <= a; i++) {
		if(a % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		
		if(isPrime(a)) {
			if(mp.find(a) != mp.end()) {
				scoreA -= 1000;
			} else {
				mp[a] = 1;
				pqA.push(a);	
				if(pqA.size() > 3) pqA.pop();
			}
		} else {
			if(pqB.size() >= 3) scoreB += pqB.top();
			else scoreB += 1000;
		}
		
		if(isPrime(b)) {
			if(mp.find(b) != mp.end()) {
				scoreB -= 1000;
			} else {
				mp[b] = 2;
				pqB.push(b);
				if(pqB.size() > 3) pqB.pop();
			}
		} else {
			if(pqA.size() >= 3) scoreA += pqA.top();
			else scoreA += 1000;
		}
	}
	
	if(scoreA > scoreB) cout << "소수의 신 갓대웅";
	else if(scoreA < scoreB) cout << "소수 마스터 갓규성";
	else cout << "우열을 가릴 수 없음";
}