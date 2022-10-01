//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Approach - 1
    // Time Complexity 0(n^3)
    
    string longestPalin1 (string S) {
        // code here
        string ans = "";
        int maxLength = 0;
        int n = S.length();
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = i; j < n; j++){
                str += S[j];
                string rev = str;
                reverse(rev.begin(), rev.end());
                int x = rev.length();
                if((str == rev) && (x > maxLength)){
                    
                    maxLength = x;
                    ans = str;
                    
                }
            }
        }
        
        return ans;
    }

    // approach - 2
    // Time Complexity 0(n^2)
    //Here two cases can be done 

    string longestPalin (string S) {
        // code here
        int low, high;
        int n = S.length();
        string ans;
        int s = 0, e = 0;
        int maxL = 0;
        for(int i = 1; i < n; i++){
            low = i-1;
            high = i;
            // for even length pallindrome
            while(S[low] == S[high] && high-low+1 <= n){
                if(high - low > maxL){
                    s = low;
                    e = high;
                    maxL = e - s;
                }
                low--;
                high++;
            }
            low = i-1;
            high = i+1;
            // for odd length pallindrome
            while(S[low] == S[high] && high-low+1 <= n){
                if(high - low > maxL){
                    s = low;
                    e = high;
                    maxL = e-s;
                }
                low--;
                high++;
            }
        }
        for(int i = s; i <= e; i++){
            ans += S[i];
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
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends