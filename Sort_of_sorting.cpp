#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool firstTC = true;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		} 
		vector<string> names(n);
		for (int i=0; i < n; i++) {
			cin >> names[i];
		}
		stable_sort(names.begin(), names.end(), [](string a, string b) {
			if (a[0] != b[0]) {
				return a[0] < b[0];
			} else {
				return a[1] < b[1];
			}
		});
		if (!firstTC) {
			cout << endl;
		}
		firstTC = false;
		for (int i = 0; i < n; i++) {
			cout << names[i] << endl;
		}
	}
	return 0;
}
