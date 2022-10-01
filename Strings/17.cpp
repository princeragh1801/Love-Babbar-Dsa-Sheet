//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // This solution gives TLE
    
    /*You are required to complete below method */
    void solve(string str, string output, int index, vector<string> &ans){
        // Base Case
        if(index >= str.length()){
            if(output.length() > 0){
                ans.push_back(output);
                return;
            }
        }

        // Exclude
        solve(str, output, index+1, ans);

        // Include
        output.push_back(str[index]);
        solve(str, output, index+1, ans);
    }

    long long int  countPS(string str)
    {
       //Your code here
       vector<string> ans;
       string output = "";
       int index = 0;
       solve(str, output, index, ans);
       long long count = 0;
        for(auto it:ans){
            string st = it;
            reverse(st.begin(), st.end());
            if(st == it){
                count++;
            }
        }
        return count;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends