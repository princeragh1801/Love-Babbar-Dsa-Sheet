//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string, int> m;
        for(int i = 0; i < n; i++){
            m[arr[i]]++;
        }
        int currMax = 0;
        int second = 0;
        string ans = "";
        for(auto it:m){
            if(it.second > currMax){
                //second = currMax;
                currMax = it.second;

            }
            // else if(it.second>second){
            //     //second = it.second;
            //     ans = it.first;
            // }
        }
        for(auto it:m){
            if(it.second > second && it.second < currMax){
                ans = it.first;
                second = it.second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends