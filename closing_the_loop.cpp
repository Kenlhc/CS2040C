#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int casenum = 1;
	int rope = 0;
	for (int i = 0; i < N; i++) {
		int S; cin >> S;
		int red[S] = {0};
		int blue[S] = {0};
		if (S == 1) {
			int length; cin >> length;
			char colour; cin >> colour;
			cout << "Case #" << casenum << ":" << " " << rope << endl;
			casenum++;
		} else {
			for (int i = 0; i < S; i++) {
				int length; cin >> length;
				char colour; cin >> colour;
				if (colour == 'R') {
					red[i] = length;
				} else {
					blue[i] = length;
				}
			}
			sort(red, red + S, greater<int>());
			sort(blue, blue + S, greater<int>());
			rope = 0;
			int index = 0;
			while ((red[index] != 0) && (blue[index] != 0)) {
				rope += red[index] - 1;
				rope += blue[index] - 1;
				index++;
			}
			cout << "Case #" << casenum << ":" << " " << rope << endl;
			casenum++;
		}
	}
	return 0;
}
