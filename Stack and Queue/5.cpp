//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        int n = x.length();
        for(int i = 0; i < n; i++){
            if(st.empty() && (x[i] == ']'||x[i] == '}' || x[i] == ')')){
                return false;
            }
            else if(x[i] == '{' || x[i] == '[' || x[i] == '('){
                st.push(x[i]);
            }
            else{
                if((x[i] == '}' && st.top() != '{') || (x[i] == ')' && st.top() != '(') || (x[i] == ']' && st.top() != '[') ){
                    return false;
                }
                else{
                    
                    st.pop();
                   
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends