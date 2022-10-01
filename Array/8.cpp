// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 // First and last occurence of x
 // Approach - 1
 // Iterate through whole array and get the desired result 
 // Time Complexity 0(n)
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v;
    int f = -1, l = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == x && f == -1){
            f = i;
            l = i;
            
        }
        else if(arr[i] == x && f != -1){
            l = i;
        }
    }
    v.push_back(f);
    v.push_back(l);
    return v;
}

// Approach - 2
// Two pointer Approach
// Time Complexity 0(logn)
vector<int> find1(int arr[], int n , int x )
{
    // code here
    vector<int> v;
    int f = -1, l = -1;
    int low = 0, high = n-1;
    while(low <= high){
        if(f != -1 && l != -1){           
            break;
        }
        if(arr[low] != x){
            low++;
        }
        if(arr[high] != x){
            high--;
        }
        if(arr[low] == x){
            f = low;
        }
        else if(arr[high] == x){
            l = high;
        }
    }
    v.push_back(f);
    v.push_back(l);
    return v;
}
// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends