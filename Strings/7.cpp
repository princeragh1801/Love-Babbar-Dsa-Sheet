//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Approach -1
    // Time complexity 0(n)
    // check if number of 0's and 1's are equal or not
    // if equal return the ans 
    
    int maxSubStr(string str){
        //Write your code here
        int cnt0 = 0, cnt1 = 0, ans = 0;
        if(str.length()%2 != 0){
            return -1;
        }
        for(int i = 0; i < str.length(); i++){
            if(str[i]=='0'){
                cnt0++;
            }
            if(str[i] == '1'){
                cnt1++;
            }
            if(cnt0 == cnt1){
                ans++;
            }
        }
        if(cnt0 != cnt1){
            return -1;
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
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends