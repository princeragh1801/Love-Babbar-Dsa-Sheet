//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    
    // Approach - 1
    // Take two array
    // One for positive numbers
    // Other one for negative numbers
    // rearrange them 
    // Time Complexity 0(N)
    // Space Complexity 0(N)
    void rearrange(int arr[], int n) {
	    // code here
        vector<int>pos;
        vector<int>neg;
        for(int i = 0; i < n; i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        int k = 0, i = 0, j = 0;
        while(k < n){
            if(i < pos.size()){
                arr[k++] = pos[i++];
            }
            if(j < neg.size()){
                arr[k++] = neg[j++];
            }
        }
	}

    
	void rearrange(int arr[], int n) {
	    // code here
        int pos = 0, neg = 1;
        while(pos < n && neg < n){
            if(pos >= 0){
                pos += 2;
            }
            else if(neg < 0){
                neg += 2;
            }
            else{
                swap(arr[neg], arr[pos]);
                neg += 2;
                pos += 2;
            }
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends