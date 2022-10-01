//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array

    // Time Complexity 0(n)
    // Space Complexity 0(n)
    int majorityElement(int a[], int size)
    {
        
        // your code here
       unordered_map<int, int> m;
       int x = size/2;
       for(int i = 0; i < size; i++){
        m[a[i]]++;
        if(m[a[i]] > x){
            return a[i];
        }
       } 
       if(m[a[size-1]] > x){
        return a[size-1];
       }
       return -1;
    }


    // Approach -2
    // First of All 
    // Find the candidate
    // Now check its majority
    // If it satisfy the given condition
    // return candidate
    // return -1
    int findCandidate(int arr[], int n){
        int candidate = -1;
        int votes = 0;
        for(int i = 0; i < n; i++){
            if(votes == 0){
                votes = 1;
                candidate = arr[i];
            }
            else if(arr[i] == candidate){
                votes++;
            }
            else{
                votes--;
            }

        }
        return candidate;
    }

    bool isMajority(int arr[], int n, int candidate){
        //int candidate = findCandidate(arr, n);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == candidate){
                count++;
            }
        }
        if(count > n/2){
            return true;
        }
        return false;
    }
    int majorityElement(int a[], int size)
    {
        
        // your code here
       int candidate = findCandidate(a, size);
        if(isMajority(a, size, candidate)){
            return candidate;
        }
       return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends