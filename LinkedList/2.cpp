//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:

    // Approach - 1
    // Extra 0(N) space required
    struct node *reverse1(struct node *head, int k)
    {
        // Complete this method
        vector<int> v;
        node *ptr = head;
        while (ptr != NULL)
        {
            v.push_back(ptr->data);
            ptr = ptr->next;
        }
        int x = 0;
        while (x + k <= v.size())
        {
            
            reverse(v.begin() + x, v.begin() + x + k);
            // debug(v);
            x += k;
        }
        if(x + k > v.size()-k){
            reverse(v.begin()+x, v.end());
        }
        // debug(v)
        ptr = head;
        // reverse(v.end() - k + 1, v.end());
        for (auto it : v)
        {
            ptr->data = it;
            ptr = ptr->next;
        }
        return head;
    }



    struct node* reverseList(node *head, node*last)
    {
        // code here
        // return head of reversed list
        node *ptr = head;
        node *q = NULL;
        node *r = head->next;

        while(r != last){
            ptr->next = q;
            q = ptr;
            ptr = r;
            r = r->next;
        }
        ptr->next = q;
        q = ptr;
        ptr = r;
        head = q;
        return head;
    }
    struct node *reverse2 (struct node *head, int k)
    { 
        // Complete this method
        node *ptr = head;
        int i = 0;
        node *start = ptr;
        node *end = ptr;
        while(ptr != NULL){
            i++;
            if(i%k == 0){
                reverseList(start, end);
                start = ptr->next;
            }
            end = ptr;
            ptr = ptr->next;
        }
        if(i%k != 0){
            reverseList(start, end);
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse2(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends

