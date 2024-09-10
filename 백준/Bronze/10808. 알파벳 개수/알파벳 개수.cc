#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	vector<int> arr(26, 0); 
	string word;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		int it = find(v.begin(), v.end(), word[i]) - v.begin();
		arr[it] += 1;	
	}
	for (auto i : arr) cout << i << " ";
	
}