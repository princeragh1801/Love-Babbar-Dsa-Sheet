//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.

    // Brute force approach 
    // Time 0(n^2)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int celeb = -1;
        for(int i = 0; i < n; i++){
            int flag = 0;
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){// i can't be a celebrity
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){//i may be a celebrity because doesn't know anyone
                int k = 0;
                flag = 1;
                while(k < n){
                    // checking if our candidate known by everyone or not
                    if(M[k][i] == 0 && k != i){
                        flag = 0;
                        break;
                    }
                    k++;
                }
                if(flag == 1){
                    celeb = i;
                    break;
                }
            }
        }
        return celeb;
    }

    //  Best approach to solve this
    // Time Complexity: O(n)
    // Space Complexity: O(1) No extra space is required.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int i = 0, j = n-1;
        while(i < j){
            // here j can't be a celebrity, but maybe
            if(M[j][i] == 1){
                j--;
            }
            else{
                // i can't be a celebrity, j maybe
                i++;
            }
        }
        // here is our candidate
        int candidate = i;
        for(i = 0; i<n; i++){
            if(i != candidate){
                // checking simultaneously candidate should be known by everyone and doesn't know anyone
                if(M[i][candidate] == 0 || M[candidate][i] == 1){
                    return -1;
                }
            }
        }
        return candidate;
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends