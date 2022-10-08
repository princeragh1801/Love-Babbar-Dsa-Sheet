// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    // push the half list in stack 
    // check if other half is equal or not 
    // Time 0(N)
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *ptr = head;
        stack<int> st;
        int cnt = 0;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
        int mid = cnt/2;
        ptr = head;
        while(mid--){
            st.push(ptr->data);
            ptr = ptr->next;
        }
        if(cnt%2 != 0){
            st.push(ptr->data);
        }
        while(!st.empty()){
            if(st.top() != ptr->data){
                return false;
            }
            ptr = ptr->next;
            st.pop();
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends