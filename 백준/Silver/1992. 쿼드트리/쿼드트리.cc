#include<bits/stdc++.h>
using namespace std;

int n, y, x, ret, ny, nx;
int a[65][65];
bool visited[65][65];
string s;
string result;

bool isUniform(int n1, int n2, int m1, int m2) {
	int value = a[n1][m1];
	for(int i = n1; i < n2; i++) {
		for(int j = m1; j < m2; j++) {
			if (a[i][j] != value) return false;
		}
	}
	return true;
} 

void go(int n1, int n2, int m1, int m2) {
	
	if(isUniform(n1, n2, m1, m2)) {
		result += to_string(a[n1][m1]);
		return;
	}
	
 	result += "(";
    int mid_n = (n1 + n2) / 2;
    int mid_m = (m1 + m2) / 2;

    go(n1, mid_n, m1, mid_m); 
    go(n1, mid_n, mid_m, m2); 
    go(mid_n, n2, m1, mid_m);
    go(mid_n, n2, mid_m, m2);
    result += ")";
 
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < n; j++) {
			a[i][j] = s[j] -'0';
		}
	}
	go(0, n, 0, n);
	cout << result;
}