#include <bits/stdc++.h>
using namespace std;

class contestants_info {
    public: 
    int s;
    int p;
    int f;
    int o;
    int total_score = 0;
    int og_index;
};

int main() {
    int n; cin >> n;
    int score[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sum = 0;
    int average = 0;
    int count = 0;
    bool swapped;
    bool first_count;
    contestants_info contestants[n];
    for (int i = 0; i < n; i++) {
        cin >> contestants[i].s;
        cin >> contestants[i].p;
        cin >> contestants[i].f; 
        cin >> contestants[i].o;
        contestants[i].og_index = i;
    }

    for (int i = 0; i < n - 1; i ++) { // to arrange them in descending order based on number of problems solved
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (contestants[j].s < contestants[j+1].s) {
                swap(contestants[j], contestants[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
    
    for (int i = 0; i < n - 1; i ++) { // to arrange in ascending order based on time penalty
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((contestants[j].s == contestants[j+1].s) && (contestants[j].p > contestants[j+1].p)) {
                swap(contestants[j], contestants[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }

    for (int i = 0; i < n - 1; i ++) { // to arrange in ascending order based on last accepted solution in minutes
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((contestants[j].s == contestants[j+1].s) && (contestants[j].p == contestants[j+1].p) && (contestants[j].f > contestants[j+1].f)) {
                swap(contestants[j], contestants[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i < 30) {// to first store all scores in each contestant since they are already ranked
            contestants[i].total_score += score[i];
        } 
    }
	first_count = false;
    for (int i = 0; i < n - 1; i ++) { //to check for equality and subsequently, sum up their scores
		if ((contestants[i].s == contestants[i+1].s) && (contestants[i].p == contestants[i+1].p) && (contestants[i].f == contestants[i+1].f)) {
			if (!first_count) {
				sum = contestants[i].total_score;
				count++;
				first_count = true;
			}
			sum += contestants[i+1].total_score;
			count++;
			if (i == n - 2) {
				average = ceil((double)sum/count);
				for (int j = i + 2 - count; j < i + 2; j++) {
					contestants[j].total_score = average;
				}
				sum = 0;
				count = 0;
				first_count = false;
			}
		} else {
			average = ceil((double)sum/count);
			for (int j = i + 1 - count; j < i + 1; j++) {
				contestants[j].total_score = average;
			}
			sum = 0;
			count = 0;
			first_count = false;
		}
    }
    for (int i = 0; i < n; i ++) {
        contestants[i].total_score += contestants[i].o;
    }
  
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            if (contestants[j].og_index == i) {
                cout << contestants[j].total_score << endl;
                break;
            }
        }
    }
    
    return 0;
}