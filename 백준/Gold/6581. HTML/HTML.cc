#include <bits/stdc++.h>
using namespace std;
int idx;
string s;

int main() {
    while (cin >> s) {
        if (s == "<hr>") {
            if (idx > 0) { 
                idx = 0;
                cout << "\n";
            }
            for(int i = 0; i < 80; i++) cout << "-";
            cout <<"\n";
        }

        else if (s == "<br>") {
            idx = 0;
            cout << "\n";
        }
        
		else  {
			if (idx + s.size() + 1 > 80) {
				idx = 0;
	            cout << "\n";
        	}
        	if (idx > 0) {
        		cout << " ";
        		++idx;
			}
        	cout << s;
        	idx += s.size();
		}
    }
    return 0;
}
