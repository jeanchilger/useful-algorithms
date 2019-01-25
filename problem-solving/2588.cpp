#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main () {

	map<char, int> m;
	
	string str;

	while(cin >> str) {
	
		for (char x : str) {
			if (m.find(x) == m.end()) {
				m[x] = 1;

			} else {
				m[x]++;
			}
		}
	
		int odd = 0;
		
		for (auto x : m) {
			//cout << x.second << endl;
			if (x.second % 2) {
				odd++;
			}
		}
		
		if (odd > 1) {
			cout << odd-1 << endl;
		} else {
			cout << 0 << endl;
		}
		
		m.clear();
		  
	}
    return 0;
}

