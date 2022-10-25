//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> st;
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            st.push(A[i]);

            // If we found stack top == output[j] 
            // then if next element is already in stack we pop 
            // else we push untill we find the output[j]
            while(!st.empty() && st.top() == B[j]){
                st.pop();
                j++;
            }
            
        }

        // if stack is empty that's means we can generate the output
        if(st.empty()){
            return 1;
        }
        // else we can't
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends