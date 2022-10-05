//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *ptr = head->next;
        Node *q = head;
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        while(ptr != NULL && q != NULL)
        {
            q = q->next;
            ptr = ptr->next;
            if(ptr != NULL)
            {
                ptr =ptr->next;
            }
            if(ptr == q)
            {
                return true;
            }
        }
        if(ptr == NULL)
        {
        return false;
        }
    }

    // Time 0(n)
    bool detectLoop(Node* head)
    {
        // your code here
        Node *fast = head;
        Node *slow = head;
        while(slow != NULL && fast != NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    // Time 0(n)
    // Space 0(n)
    bool detectLoop(Node* head)
    {
        // your code here
        Node *ptr = head;
        unordered_set<Node*> st;
        while(ptr != NULL){
            if(st.find(ptr) != st.end()){
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}

// } Driver Code Ends