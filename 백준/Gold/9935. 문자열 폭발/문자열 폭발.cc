#include <bits/stdc++.h>
using namespace std;
string target, a, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> target;
	
	int target_size = target.size();
	
	for(char ch: a) {
		result += ch;
		
		// 최근에 추가한 문자열이 target과 일치하면 제거 
		if(result.size() >= target_size && result.substr(result.size() - target_size) == target) {
			result.erase(result.size() - target_size);
		}
	}
	
	if(result.size()) cout << result;
	else cout << "FRULA";
}
