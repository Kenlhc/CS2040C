//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

struct research_schedule {
    int atime;
    int ltime;
    int total_time;
};

bool compbyA (research_schedule a, research_schedule b) {
    return a.atime < b.atime;
}

int main() {
    int n; cin >> n; //number of researches coming in and going out 
    int m; cin >> m; //number of minutes it takes before the workstation locks itself
    int count = 0;
    research_schedule researcher[n];
    priority_queue <int> workstation;
    for (int i = 0; i < n; i++) {
        int arrive; cin >> arrive;
        int leave; cin >> leave; 
        researcher[i].atime = arrive;
        researcher[i].ltime = leave;
        researcher[i].total_time = arrive + leave;
    }
    
    stable_sort(researcher, researcher + n, compbyA);
    workstation.push(-researcher[0].total_time); //negative value stored so that priority is the first workstation used
 
    for (int i = 1; i < n; i++) {
        while (!workstation.empty()) {
			int curr_workstation = -workstation.top(); //negate to make it positive  
            if (researcher[i].atime < -workstation.top()) { //if workstation is occupied
				break;
			}
			workstation.pop(); //we know arrival time is more than total time of researcher in the workstation when we reach this line
			if (researcher[i].atime <= curr_workstation + m) { //if arrival time <= total time needed for penelope to lock station                         
                    count += 1; //lock saved 
                    break;
			}
        } 
		workstation.push(-researcher[i].total_time); //store new total time of researcher using workspace
    }
    cout << count << endl;
}