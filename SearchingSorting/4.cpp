//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        int total = A+B+C;
        int maxi = max(A,B);
        maxi = max(maxi,C);
        int mini = min(A,B);
        mini = min(mini, C);
        return total-(maxi+mini);
    }


    int middle(int A, int B, int C){
        // A < B
        // We and B > C we Have ans A or C
        // If B < C B is our ans

        // A < C if it is A is our ans 
        // else max(B,C)is our ans
      if (A < B)
        return (B < C)? B : max(A, C);
      return (A < C)? A : max(B, C);
    }
};

//{ Driver Code Starts.
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
  
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends