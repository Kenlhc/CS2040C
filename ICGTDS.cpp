#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_cases;
	while (cin >> test_cases) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool is_stack = true;
		bool is_queue = true;
		bool is_pq = true;
		for (int i = 0; i < test_cases; i++) {
			int command; cin >> command;
			int value; cin >> value;
			if (command == 1) {
				q.push(value);
				s.push(value);
				pq.push(value);
			} else { // type 2 command
				if (q.empty() || q.front() != value) {
					is_queue = false;
				} else {
					q.pop();
				}
				if (s.empty() || s.top() != value) {
					is_stack = false;
				} else {
					s.pop();
				}
				if (pq.empty() || pq.top() != value) {
					is_pq = false;
				} else {
					pq.pop();
				}
			}
		}
		
		if (is_stack && !is_queue && !is_pq) {
			cout << "stack" << endl;
		} else if (is_queue && !is_stack && !is_pq) {
			cout << "queue" << endl;
		} else if (is_pq && !is_stack && !is_queue) {
			cout << "priority queue" << endl;
		} else if (!is_queue && !is_stack && !is_pq) {
			cout << "impossible" << endl;
		} else {
			cout << "not sure" << endl;
		}
	}
	return 0;
}