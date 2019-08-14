//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

int mybinary_search (int a[], int first, int last, int x, int y) {
	if (first < last) {
       int mid = (first + last) / 2;  // calculate maximum number of people assigned to one box
	   int box_count = 0;
       for (int i = 0; i < x; i++) {
			box_count += (a[i] + mid - 1) / mid; //count total number of boxes each containing the number of citizens found above
		}
		if (box_count <= y) {
 			return mybinary_search(a, first, mid, x, y); //search for the next most optimized citizens per box
		} else {
 			return mybinary_search(a, mid + 1, last, x, y);
		}
	}
	return first;
}

int main() {
	bool testcase = true;
	while (testcase) {
		int n; cin >> n; //number of cities 
		int b; cin >> b; //number of ballot boxes
		int population[500000];
		if (n == -1 && b == -1) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int p; cin >> p;
			population[i] = p;
		}
		int max = population[0];
		for (int i = 1; i < n; i++) {
			if(max < population[i]) {
				max = population[i]; // find 'high' for binary search 
			} 
		}  
		int start = 1; 
		cout << mybinary_search(population, start, max, n, b) << endl;
	}
	return 0;
}