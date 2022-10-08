//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

// Time 0(n+m)
// Space 0(n)

// Works fine 
// 190 test case passed out of 192
// After that gives TLE
int intersectPoint(Node* head1, Node* head2)
{
    unordered_set<Node*> s;
    int ans = -1;
    while(head1){
        s.insert(head1);

        head1 = head1->next;
    }
    while(head2){
      
        if(s.find(head2) != s.end()){
            ans = head2->data;
            break;
        }
        head2 = head2->next;
    }

    return ans;
}


// This works pretty fine
// what we are actually trying to do is
// we are finding a point from where both linked list have equal nodes
// so we can iterate through from that poit and at each point check whether the address of nodes are equal or not
// if our poiter reaches to null we simply return -1
// we return data at the point where our pointer points 

// Time 0(n+m)
// No extra space required
int intersectPoint(Node* head1, Node* head2)
{
    Node*temp1 = head1;
    Node*temp2 = head2;
    int ans = -1;
    int cnt1 = 0, cnt2 = 0;
    while(temp1){
        cnt1++;

        temp1 = temp1->next;
    }
    while(temp2){
        cnt2++;
        temp2 = temp2->next;
    }
    if(cnt1 >= cnt2){
        int x = cnt1 -cnt2;
        while(x--){
            head1 = head1->next;
        }
        while (head1 != head2)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        if(head1 != NULL){
            ans = head1->data;
        }
    }
    else{
        int x = cnt2 - cnt1;
        while(x--){
            head2 = head2->next;
        }
        while (head1 != head2)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        if(head1 != NULL){
            ans = head1->data;
        }
    }
    return ans;
}

