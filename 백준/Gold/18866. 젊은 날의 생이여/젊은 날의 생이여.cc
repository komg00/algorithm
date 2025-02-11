#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int old_min_tired = 987654321, young_min_happy = 987654321;
int young_max_tired = -987654321, old_max_happy = -987654321;
int v[1000004][2], young[1000004][2], old[1000004][2];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1]; 
    }
    
    for(int i = 0; i < n; i++) {
        if(v[i][0] != 0 && young_min_happy > v[i][0]) young_min_happy = v[i][0];
        if(v[i][1] != 0 && young_max_tired < v[i][1]) young_max_tired = v[i][1];

        young[i][0] = young_min_happy;
        young[i][1] = young_max_tired;
 	}

    for(int i = n - 1; i >= 0; i--) {
        if(v[i][0] != 0 && old_max_happy < v[i][0]) old_max_happy = v[i][0];
        if(v[i][1] != 0 && old_min_tired > v[i][1]) old_min_tired = v[i][1];

        old[i][0] = old_max_happy;
        old[i][1] = old_min_tired;
	}

    for(int i = 0; i < n - 1; i++) { 
        if(young[i][0] > old[i+1][0] && young[i][1] < old[i+1][1]) 
            cnt = i + 1;
    }
    if (cnt == 0) cnt = -1;
    cout << cnt;
}
