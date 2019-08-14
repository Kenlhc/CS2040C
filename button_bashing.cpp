//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int testc; cin >> testc; //no. of test cases
	for (int i = 0; i < testc; i++) {
		int n; cin >> n; // no. of buttons 
		int t; cin >> t; // desired cooking time
		vector <int> Adlist; 
		vector <int> check(3605, INF); // no. of presses 
		for (int j = 0; j < n; j++) {
			int time; cin >> time; // time for each button 
			Adlist.push_back(time); 
		}
		queue<int> q;
		q.push(0); 
		check[0] = 0;
		while(!q.empty()) {
			int test = q.front();
			q.pop();
			for (auto &v : Adlist) {
				int possible_time = test + v;
				if (possible_time < 0) {
					possible_time = 0;
				} else if (possible_time > 3600) {
					possible_time = 3600;
				} 
				if (check[possible_time] > check[test] + 1) {
					check[possible_time] = check[test] + 1;
					q.push(possible_time);
				}
			}
		}
		int min = check[t];
		int extra = 0;
		for (int i = t; i < 3605; i++) {
			if (check[i] != INF) {
				min = check[i]; 
				extra = i - t;
				break;
			} 
		}
		cout << min << " " << extra << endl;
	}
	return 0;
}