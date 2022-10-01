//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int i = 0, j = 0;
        int ans = 0;

        while(i < t.length() && j < s.length()){
            if(t[i] != s[j]){
                ans++;
                if(t[i] == s[j+1]){   
                    j++;
                }
                else{
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
            
        }
        ans += abs(j - s.length());
        ans += abs(i - t.length());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends