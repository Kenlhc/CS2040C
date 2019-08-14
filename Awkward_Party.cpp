//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); //important to gain speed 
	int n; cin >> n; //number of guests
	long long position = 0; 
	bool speak_same_language = false; 
	priority_queue <int> minimum; 
	map <long long, deque<long long>> mltp ;
	for (int i = 0; i < n; i++) {
		int lang; cin >> lang; 
		position++;
		mltp[lang].push_back(position);
	}
	for (auto &i : mltp) {
		if (i.second.size() >= 2) {
			speak_same_language = true;
			while (i.second.size() != 1) {
				minimum.push(i.second[0] - i.second[1]);
				i.second.pop_front();
			}
		}
	}
	if (speak_same_language) {
		cout << -minimum.top() << endl;
	} else {
		cout << n << endl;
	}
	return 0;
}
