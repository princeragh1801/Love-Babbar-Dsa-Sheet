//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char, int> m;
        int arr[26] = {0};
        for(auto it : s){
            m[it]++;
            int x = it - 97;
            arr[x]++;
        }
        vector<int> v;
        for(auto it : m){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n-k; i++){
            ans += pow(v[i], 2);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends