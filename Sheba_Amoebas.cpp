//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

int m;
int n;
string dish[110]; //represent petri dish in 2d array 

void dfs_checkhash(int row, int col) {
	dish[row][col] = '.'; // change the hashtag to a dot 
	if (row > 0 && dish[row - 1][col] == '#') { // check up
		dfs_checkhash (row - 1, col);
	} 
	if (row > 0 && col < n && dish[row - 1][col + 1] == '#') { // check northeast 
		dfs_checkhash (row - 1, col + 1);
	}
	if (col < n && dish[row][col + 1] == '#') { // check right
		dfs_checkhash (row, col + 1);
	}
	if (row < m && col < n && dish[row + 1][col + 1] == '#') { // check southeast
		dfs_checkhash (row + 1, col + 1);
	}
	if (row < m && dish[row + 1][col] == '#') { // check down
		dfs_checkhash (row + 1, col);
	} 
	if (row < m && col > 0 && dish[row + 1][col - 1] == '#') { // check southwest
		dfs_checkhash (row + 1, col - 1);
	}
	if (col > 0  &&  dish[row][col - 1] == '#') { // check left
		dfs_checkhash (row, col - 1);
	}
	if (row > 0 && col > 0 && dish[row - 1][col - 1] == '#') {
		dfs_checkhash (row - 1, col - 1);
	}
    return; 
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> m; //no. of rows 
	cin >> n; //no. of columns 
	cin.ignore(); //consume newline character 
	for (int i = 0; i < m; i++) {
		cin >> dish[i]; //takes in entire row as string 
	}
	int count = 0; 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (dish[i][j] == '#') {
				count++;
				dfs_checkhash(i,j);
			}
		}
	}
	cout << count << endl;
	return 0; 
}