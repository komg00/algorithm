#include<bits/stdc++.h>
using namespace std;
int n, temp, duration;
vector<int> v, p_sum, temp_sum;
int sum = 0;
int main() {
	cin >> n >> duration;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		p_sum.push_back(sum);
	}

	for (int i = duration - 1; i < n; i++) {
		if (i - duration <  0)
			temp_sum.push_back(p_sum[i]);
		else
			temp_sum.push_back(p_sum[i] - p_sum[i - duration]);

	}
	cout << *max_element(temp_sum.begin(), temp_sum.end()) << endl;
	
}