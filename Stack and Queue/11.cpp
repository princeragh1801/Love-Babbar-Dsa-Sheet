//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    
    

    // iterative way
    stack<int> Reverse(stack<int> St){
        stack<int> s;
        while(!St.empty()){
            int x = St.top();
            s.push(x);
            St.pop();
        }
        return s;
    }


    // Recursive way
    void insert_at_bottom(stack<int> st, int x){
        if(st.empty()){
            st.push(x);
        }
        else{
            int y = st.top();
            st.pop();
            insert_at_bottom(st, x);
            st.push(y);
        }
    }
    stack<int> Reverse(stack<int> St){
        if(St.empty()){
            return St;
        }
        int x = St.top();
        St.pop();
        St = Reverse(St);
        insert_at_bottom(St, x);

        return St;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends