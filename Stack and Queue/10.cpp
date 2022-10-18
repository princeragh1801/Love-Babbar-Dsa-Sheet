//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < S.length(); i++){
            char c = S[i];
            if(c >= '0' && c <= '9'){
                int x = c-48;
                s.push(x);
            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(c == '+'){
                    ans = b+a;
                }
                else if(c == '-'){
                    ans = b-a;
                }
                else if(c == '*'){
                    ans = b*a;
                }
                else if(c == '/'){
                    ans = b/a;
                }
                
                s.push(ans);
            }
        }
        ans = s.top();
        s.pop();
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends