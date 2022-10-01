// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // Approach-1
    // Brute Force Approach
    // Nested loops compare
    // Time Complexity 0(n^2)

    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(arr[i]+arr[j] == k){
                    count++;
                }
            }
        }
        return count;
    }

    // Approach -2
    // Better Approach
    // Using Hashmap
    // Time Complexity 0(n)
    // Space Complexity 0(n)
    
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> s;
        int count = 0;
        for(int i = 0; i < n-1; i++){
            if(s.find(k-arr[i]) != s.end()){count += s[k-arr[i]];}
            s[arr[i]]++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends