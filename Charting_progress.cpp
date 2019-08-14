#include <bits/stdc++.h>
using namespace std;

int main()
{
	string log;
	int count;
	vector <bool> inposition;
	while (getline(cin, log)) {
		int j = log.length();
		for (int i = 0; i < j; i++) {
			inposition.push_back(false);
		}
		if (log.empty()) {
			fill (begin(inposition), end(inposition), false);
 		}
		count = 0;
		for (int i = 0; i < j; i++) {
			if (log[i] == '*') {
				count++;
				log[i] = '.';
			}
		}
		for (int i = 0; i < count; i++) {
			if (log[j-1] != '*' && !inposition[j-1]) {
				log[j-1] = '*';
				inposition[j-1] = true;
			} else {
				j--;
				i--;
			}
		}
		cout << log << endl;
	} 
	return 0;
}
