#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	string c;
	cin >> c;
	int isP = 1;
	int len = c.size();
	for (int i = 0; i < len / 2; i++) {
		if(c[i] == c[len-i-1])
			continue;
		else 
			isP = 0;
			break;
	}
	cout << isP << endl;
}