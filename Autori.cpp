#include <bits/stdc++.h> 
using namespace std;

int main() {
	string s; cin >> s; //terminates reading input once a space is found 
	// string is a built-in class 
	stringstream ss(s);
	string token;

	while (getline(ss, token, '-'))
	{
		cout << token[0];
	} 
	return 0;
}