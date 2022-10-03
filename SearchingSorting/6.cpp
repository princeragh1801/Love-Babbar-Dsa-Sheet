//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

// Naive Approach
// Check for all the pairs
// Time Complexity 0(n^2)
bool findPair(int arr[], int size, int n){
    //code
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(abs(arr[i]-arr[j]) == n){
                return true;
            }
        }
    }
    return false;
}

// Approach - 2
// Use Extra space
// Time complexity 0(n)
bool findPair(int arr[], int size, int n){
    //code
    unordered_set<int> s;
    for(int i = 0; i < size; i++){
        int x = n+arr[i];
        if(s.find(x) != s.end()){
            return true;
        }
        x = abs(n-arr[i]);
        if(s.find(x) != s.end()){
            return true;
        }
        s.insert(arr[i]);

    }
    return false;
}