//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        if(x == y){
            return x;
        }
        int mask;
        if(r-l+1 == 32){
            mask = ((1<<(r-l+1))-1);
        } 
        else{
            mask = (1 << (r-l+1));
        }
        mask--;
        mask = (mask<<(l-1));
        mask = (mask&y);
        x = (x|mask);
        
        
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends