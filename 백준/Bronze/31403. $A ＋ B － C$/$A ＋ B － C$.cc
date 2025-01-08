#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;
	cout << a + b - c << "\n";
	string sum = to_string(a) + to_string(b);
	cout << stoi(sum) - c << "\n";
}