//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.

//  It gives TLE
queue<int> rev(queue<int> q)
{
    // add code here.
    if(q.empty()){
        return q;
    }
    int x = q.front();
    q.pop();
    q = rev(q);
    q.push(x);
    return q;
    
}


//  It uses extra space
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> st;
    while(!q.empty()){
        int x = q.front();
        st.push(x);
        q.pop();
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        q.push(x);
    }
    return q;
    
}