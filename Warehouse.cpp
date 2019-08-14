//A0189763J
//Lee Hong Chien, Kenneth 
//Lab No.12
//Aaryam Srivastava

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); //important to gain speed 
    int T; cin >> T; // no. of testcases  
    for (int i = 0; i < T; i++) {
        int N; cin >> N; // no. of toys  
        unordered_map <string, int> mttn;
        for (int j = 0; j < N; j++) { 
            string toy; cin >> toy;
            int number; cin >> number;
            mttn[toy] += number; 
        }
        vector <pair <int, string>> transfer; // to transfer the items for sorting manually 
        for (auto &it : mttn) {
            transfer.push_back({-it.second, it.first}); // negative so that standard lib sort will sort in descending order for number for ascending for toy  
        }
        sort (transfer.begin(), transfer.end());
        cout << transfer.size() << endl; 
        for (auto &i : transfer) {
            cout << i.second << " " << -i.first << endl; 
        }
    }
    return 0;
}

