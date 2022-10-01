//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Approach -1
// Brute Force Approach
// Expected Time Complexity: O(n^2)

string isSubset(int a1[], int a2[], int n, int m) {
    for(int i = 0; i < m; i++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(a2[i] == a1[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return "No";
        }
    }
    return "Yes";
}

// Approach - 2
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> s;
    for(int i = 0; i < n; i++){
        s[a1[i]]++;
    }
    string ans = "Yes";
    for(int i = 0; i < m; i++){
        if(s[a2[i]] == 0){
            ans = "No";
            break;
        }
        s[a2[i]]--;
    }
    return ans;
}