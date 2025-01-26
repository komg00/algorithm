#include <bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<char> op;
vector<int> num;

int oper(char a, int b, int c) {
	if(a == '+') {
		return b + c;
	} else if(a == '-') {
		return b - c;
	} else if(a == '*') {
		return b * c;
	}
}

void go(int idx, int sum) {
	if(idx == num.size() - 1) {
		ret = max(ret, sum);
		return;
	}
	go(idx + 1, oper(op[idx], sum, num[idx + 1]));
	if(idx + 2 <= num.size() - 1) {
		int temp = oper(op[idx + 1], num[idx + 1], num[idx + 2]);
		go(idx + 2, oper(op[idx], sum, temp));
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
			op.push_back(s[i]);
		} else num.push_back(s[i] - '0');
	}
	go(0, num[0]);
	cout << ret;
}