#include <bits/stdc++.h>
using namespace std;

int main() {
	int s; cin >> s; //no. of syllables 
	int n; cin >> n; //no. of players
	deque <int> coconut; 
	deque <int> track;
	int count = 1;
	for (int i = 0; i < n; i++) {
		coconut.push_back(2);
		track.push_back(count);
		count++;
	} 
	while (coconut.size() != 1) {
		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i < s - 1; i++) {
			temp1 = coconut.front();
			temp2 = track.front();
			coconut.pop_front();
			track.pop_front();
			coconut.push_back(temp1);
			track.push_back(temp2);
		}
		int player = track.front();
		if (coconut.front() == 2) {
			coconut.front() = 1;
			coconut.push_front(1);
			track.push_front(player);
		} else if (coconut.front() == 1) {
			coconut.front() = 0;
			coconut.pop_front();
			coconut.push_back(0);
			track.pop_front();
			track.push_back(player);
		} else if (coconut.front() == 0) {
			coconut.pop_front();
			track.pop_front();
		} 
	}
	cout << track.front() << endl; 
	return 0;
}