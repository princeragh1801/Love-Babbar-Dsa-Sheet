//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    // One way is to solve this problem is use two vectors push them accordingly and after it assign the values then return head

    // another way is implemented below
    Node* divide(int N, Node *head){
        // code here
        if(!head || !head->next){
            return head;
        }
        Node *evenD = new Node(-1);
        Node *oddD = new Node(-1);
        Node *even = evenD, *odd = oddD;
        Node *ptr = head;
        while(ptr){
            if((ptr->data)%2 == 0){
                even->next = ptr;
                even = ptr;
                
            }
            else{
                odd->next = ptr;
                odd = ptr;
                
            }
            ptr = ptr->next;
        }
        odd->next = NULL;
        even->next = oddD->next;
        head = evenD->next;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends