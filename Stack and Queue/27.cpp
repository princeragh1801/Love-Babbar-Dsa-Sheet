//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        int flag = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(st.top() == ')' || st.empty()){
                    return 1;
                }
                while(st.top() != '('){
                    
                    if(st.top() == '*' || st.top() == '/'|| st.top() == '+'|| st.top() == '-'){
                        flag = 1;
                    }
                    st.pop();
                }
                if(flag == 0){
                    return 1;
                }
                st.pop();
                flag = 0;
            }
            else{
                st.push(s[i]);
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends