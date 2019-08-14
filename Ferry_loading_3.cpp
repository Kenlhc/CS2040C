// A0189763J
// Lee Hong Chien, Kenneth 
// Lab No.12
// Aaryam Srivastava

#include <bits/stdc++.h> 
using namespace std;

struct side_left {
	queue <int> leftside;
	queue <int> indexL;
	queue <int> resultsL;
};

struct side_right {
	queue <int> rightside;
	queue <int> indexR;
	queue <int> resultsR;
};

int main() { 
	int c; cin >> c; //number of test cases 
	for (int i = 0; i < c; i++) {
		int n; cin >> n; //number of cars ferry can take 
		int t; cin >> t; //time taken to cross the river
		int m; cin >> m; //no. of lines
		int time_tracker = 0; 
		int count = -1; //to signify first time there
		side_left left;
		side_right right;
		bool ferry_left = true;
		bool not_empty = true;
		bool wait = false;
		for (int j = 0; j < m; j++) {
			int time; cin >> time;
			string command; cin >> command;
			if (command == "left") {
				left.leftside.push(time);
				left.indexL.push(j);
			} else {
				right.rightside.push(time);
				right.indexR.push(j);
			}
		}
		while (not_empty) { //true until broken by condition inside 
			if (left.leftside.empty() && right.rightside.empty()) {
				not_empty = false; 
			}
			if (ferry_left) { // on the left or start from left anyway
				if (wait) {
					if(left.leftside.empty()) {
						time_tracker = right.rightside.front();
					} else if (right.rightside.empty()) {
						time_tracker = left.leftside.front();
					} else {
						if (left.leftside.front() > right.rightside.front()) {
							time_tracker = right.rightside.front();
						} else {
							time_tracker = left.leftside.front();
						}
					}
					wait = false;
				} else if (count > 0) { //means loaded 
					time_tracker += t; // travelling time
					for (int j = 0; j < count; j++) {
						right.resultsR.push(time_tracker); 
					}
					count = 0; 
				} else if (count == 0) { //means empty
					time_tracker += t; //travel time to pick up waiting car or add waiting time
				} else if (count == -1) { // first time there, don't do anything
					count = 0;
				} 
				for (int j = 0; j < n; j++) {
					if (left.leftside.front() <= time_tracker && !left.leftside.empty()) {
						left.leftside.pop(); //simulate load
						count++; //count number of cars loaded
						ferry_left = false; //going to go right 
					} else if (right.rightside.front() <= time_tracker && !right.rightside.empty()) {
						ferry_left = false; //go to right if car is waiting and no car on left 
					} 
				}
				if (left.leftside.front() > time_tracker && count == 0) {
					if (ferry_left) {
						wait = true;
					}
				} else if (right.rightside.front() > time_tracker && count == 0) {
					if (ferry_left) {
						wait = true;
					} 
				}
			} else if (!ferry_left) { // on the right 
				if (wait) {
					if(left.leftside.empty()) {
						time_tracker = right.rightside.front();
					} else if (right.rightside.empty()) {
						time_tracker = left.leftside.front();
					} else {
						if (left.leftside.front() > right.rightside.front()) {
							time_tracker = right.rightside.front();
						} else {
							time_tracker = left.leftside.front();
						}
					}
					wait = false;
				} else if (count > 0) { //means loaded 
					time_tracker += t; // travelling time
					for (int j = 0; j < count; j++) {
						left.resultsL.push(time_tracker); 
					}
					count = 0; 
				} else if (count == 0) { //means empty
					time_tracker += t; //travel time to pick up waiting car 
				} 
				for (int j = 0; j < n; j++) {
					if (right.rightside.front() <= time_tracker && !right.rightside.empty()) {
						right.rightside.pop(); //simulate load
						count++; //count number of cars loaded
						ferry_left = true; //going to go left 
					} else if(left.leftside.front() <= time_tracker && !left.leftside.empty()) {
						ferry_left = true; // go left if got car waiting on left
					} 
				}
				if (left.leftside.front() > time_tracker && count == 0) {
					if(!ferry_left) {
						wait = true;
					}
				} else if (right.rightside.front() > time_tracker && count == 0) {
					if(!ferry_left) {
						wait = true; 
					}
				}
			} 
		}
		for (int j = 0; j < m; j++) {
			if(left.indexL.front() == j) {
				cout << left.resultsL.front() << endl;
				left.resultsL.pop();
				left.indexL.pop();
			} else if (right.indexR.front() == j) {
				cout << right.resultsR.front() << endl;
				right.resultsR.pop();
				right.indexR.pop();
			}
		}
		cout << endl;
	}
	return 0;
}