#include <bits/stdc++.h>
using namespace std;

int n, score1, score2, asum, bsum;

int timeToSeconds(int m, int s) {
    return m * 60 + s;
}

int main() {
    cin >> n;
    int last_time = 0;

    for (int i = 0; i < n; i++) {
        int team;
        string r;
        cin >> team >> r;

        int m = stoi(r.substr(0, 2));
        int s = stoi(r.substr(3, 2));
        int current_time = timeToSeconds(m, s);

        // 시간 계산
        if (score1 > score2) {
            asum += (current_time - last_time);
        } else if (score1 < score2) {
            bsum += (current_time - last_time);
        }

        // 점수 업데이트
        if (team == 1) {
            score1++;
        } else {
            score2++;
        }

        last_time = current_time;
    }

    // 마지막 남은 시간 계산
    int end_time = timeToSeconds(48, 0);
    if (score1 > score2) {
        asum += (end_time - last_time);
    } else if (score1 < score2) {
        bsum += (end_time - last_time);
    }

    printf("%02d:%02d\n", asum / 60, asum % 60);
    printf("%02d:%02d\n", bsum / 60, bsum % 60);

    return 0;
}