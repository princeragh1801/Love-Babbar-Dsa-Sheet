//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> aux;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                aux.push_back(Mat[i][j]);
            }
        }
        sort(aux.begin(), aux.end());
        int it = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = aux[it++];
            }
        }

        return Mat; 
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends