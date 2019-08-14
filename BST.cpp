#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); //important to gain speed 
	int N; cin >> N; // length of the sequence
	map <int, int> tree;
	int count = 0;
	int depth;
	int numbers;
	cin >> numbers; 
	int root = numbers;
	cout << count << endl;
	tree.insert(make_pair(root, root));
	for (int i = 1; i < N; i++) {
		cin >> numbers;
		depth = 0;
		if (numbers > root) { 
			tree.insert(make_pair(numbers, numbers));
			for (auto &j : tree) {
				if (j.first != numbers) {
					depth++;
				} 
			}
			count += depth;
			cout << count << endl;
		} else {
			tree.insert(make_pair(numbers, numbers));
			for (auto &j : tree) {
				if (j.first != numbers) {
					depth++;
				} 
			}
			count += depth; 
			cout << count << endl;
		}
	}
	return 0; 
}