//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    // Time complexity 0(n)
    // Space complexity 0(n)
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll ans = 0;
        unordered_map<int, int> st;
        ll sum = 0;
        st[sum]++;
        for(auto &it : arr){
            sum += it;
            if(st[sum]){
                ans += st[sum];
            }
            st[sum]++;
        }
        return ans;
    }


    // time complexity 0(n^2)
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll s = 0;
            for(ll j = i; j < n; j++){
                s += arr[j];
                if(s == 0){
                    ans++;
                }
            }
        }
        return ans;
    }

    // Naive Approach
    // Check for all the subarray 
    // return the count 

    // Time complexity 0(n^3)
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(ll j = i; j < n; j++){
                ll s= 0;
                for(ll k =i; k <j+1; k++){
                    s += arr[k];
                }
                if(s == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends